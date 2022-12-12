from collections import namedtuple
import cv2 as cv
import numpy as np
from time import time
# problems with PnP https://github.com/opencv/opencv/issues/8813

# toggle for showing image to help with debugging
DEBUG = True

# toggle for stereo vs mono camera
IS_STEREO = True

# MARKER
NP_CALIB_DATA = './camera/calibration_data/zed_data.npz'
MARKER_SIZE = 14.7  # cm
# for detection of markers in subpixels
# we search for subpixels inside window and outside zero zone
WIN_SIZE = (5, 5)
ZERO_ZONE = (-1, -1)
# criteria specifies desired accuracy, number of iterations, and termination criteria
# https://docs.opencv.org/4.x/d9/d5d/classcv_1_1TermCriteria.html
CRITERIA = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_COUNT, 40, 0.001)


# TEXT
FONT = cv.FONT_HERSHEY_SIMPLEX
FONT_SCALE = 1
FONT_THICK = 2

# COLORS
BLUE = (255, 0, 0)
GREEN = (0, 255, 0)

# helper function to simplify cropping photo
def crop(image):
    return image[0:image.shape[0], 0:image.shape[1]//2]

def main():
    # define object for storing tag corner data
    # note: pos is pixel distance horizontally from center of image
    Tag = namedtuple('Tag', ['id', 'tr', 'tl', 'br', 'bl', 'pos', 'dist'])

    # load calibration data from numpy file
    with np.load(NP_CALIB_DATA) as X:
        mtx, dist, _ , _ = [X[i] for i in ('mtx','dist','rvecs','tvecs')]

    # define aruco tagdictionary, tag detection parameters, 
    # and video capture feed for tag detection
    marker_dict = cv.aruco.Dictionary_get(cv.aruco.DICT_4X4_50)
    param_markers = cv.aruco.DetectorParameters_create()
    cap = cv.VideoCapture(0)
    if not cap.isOpened(): return


    # start printing timer
    start_time = time()

    # loop until 'q' key is pressed
    while True:
        # create set to store ids for discovered tags, and list to hold tag data
        tag_ids = set()
        tags = []  

        _, frame = cap.read()  # read current frame from camera
        if IS_STEREO: frame = crop(frame)
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

        # detect markers in frame, get ids and corners of markers
        corners, ids, _ = cv.aruco.detectMarkers(
            frame, marker_dict, parameters=param_markers
        )

        if corners:  # if there are corners detected
            # use a SubPixel corner refinement method to improve marker detection
            for corner in corners:
                cv.cornerSubPix(
                    gray, np.array(corner[0], dtype='float32'), WIN_SIZE, ZERO_ZONE, CRITERIA
                )

            # improve by using cv2.SolvePnP() instead
            # https://docs.opencv.org/4.x/d5/d1f/calib3d_solvePnP.html
            # https://docs.opencv.org/3.4/d9/d0c/group__calib3d.html#ga357634492a94efe8858d0ce1509da869
            # Pose refinement method to improve pose estimation
            rvecs, tvecs, _ = cv.aruco.estimatePoseSingleMarkers(
                corners, MARKER_SIZE, mtx, dist
            )

            for tag_id, corners, i in zip(ids, corners, range(0, ids.size)):

                # clean corner data and package as a single tuple
                clean_corners = corners.reshape(4, 2).astype(int) 
                tag = Tag(
                    tag_id[0],
                    clean_corners[0].ravel(),
                    clean_corners[1].ravel(),
                    clean_corners[2].ravel(),
                    clean_corners[3].ravel(),
                    int((clean_corners[0].ravel()[0] + clean_corners[1].ravel()[0])/2 - frame.shape[1]/2),
                    round(tvecs[i][0][2],2)
                )

                # add tag to dataset of tags if not already present
                if tag.id not in tag_ids:
                    tag_ids.add(tag.id)
                    tags.append([*tag])

                # draw vector lines and data to frame if debugging
                if DEBUG:  
                    cv.polylines(  # create vector lines to draw
                        frame, [corners.astype(np.int32)], True, BLUE, 4, cv.LINE_4
                    )
                    # draw position vector, position in frame, and distance from camera
                    cv.drawFrameAxes(frame, mtx, dist, rvecs[i], tvecs[i], 4, 4)
                    cv.putText(frame, f'id: {tag.id} Dist: {tag.dist}', tag.tr, FONT, FONT_SCALE, GREEN, FONT_THICK, cv.LINE_AA)
                    cv.putText(frame, f'Pos: {tag.pos}', tag.br, FONT, FONT_SCALE, GREEN, FONT_THICK, cv.LINE_AA)

        if DEBUG: cv.imshow('Debug camera view', frame)  # display image if we're debugging
        
        # print discovered tags every 10 seconds
        if time() - start_time > 1:
            start_time = time()
            if len(tags) == 0:
                print('No tags found')
            else:
                for t in tags: print(f'Tag found: {t}') 

        if cv.waitKey(1) & 0xFF == ord('q'):  # quit when 'q' is pressed
            break
    
    # release all resources
    cap.release()
    cv.destroyAllWindows()


if __name__ == '__main__':
    main()