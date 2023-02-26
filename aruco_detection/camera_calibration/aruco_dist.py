from collections import namedtuple
import cv2
import numpy as np
from time import time



###HYPERPARAMETERS##############################################################
# length of markers we are detecting
MARKER_SIZE = 14.7  # cm

# for detection of markers in subpixels
# we search for subpixels inside window and outside zero zone
WIN_SIZE = (5, 5)
ZERO_ZONE = (-1, -1)
# specifies desired accuracy, number of iterations, and termination criteria
CRITERIA = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_COUNT, 40, 0.001)
# https://docs.opencv.org/4.x/d9/d5d/classcv_1_1TermCriteria.html

PATH_TO_DATA = '.'
DATA_NAME = 'logitech_webcam_data.npz'

###HELPER FUNCTIONS#############################################################
# helper function to simplify cropping photo
def crop(image):
    return image[0:image.shape[0], 0:image.shape[1]//2]

# helper function for printing text on screen
def print_text(image, text, pos):
    cv2.putText(
        image, text, pos, cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv2.LINE_AA
    )



###TAG DETECTOR#################################################################
# define object for storing tag corner data
# note: pos is pixel distance horizontally from center of image
Tag = namedtuple('Tag', ['id', 'tr', 'tl', 'br', 'bl', 'pos', 'dist'])

class Aruco_Detector():
    def __init__(self, calibration_data, is_stereo=False, show_gui=False):
        self.show_gui = show_gui
        self.is_stereo = is_stereo

        # load calibration data from numpy file
        with np.load(f'{PATH_TO_DATA}/calibration_data/{calibration_data}') as X:
            self.mtx, self.dist, _ , _ = [X[i] for i in ('mtx','dist','rvecs','tvecs')]

        # define aruco tagdictionary, tag detection parameters, 
        # and video capture feed for tag detection
        self.dictionary = cv2.aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
        self.parameters = cv2.aruco.DetectorParameters()
        #self.parameters = cv2.aruco.DetectorParameters_create()

        self.cap = cv2.VideoCapture(0)
        #self.detector = cv2.aruco.ArucoDetector(self.dictionary, self.parameters)

    def detect_tags(self):
        # create set to store ids for discovered tags, and list to hold tag data
        tag_ids = set()
        tags = []  

        # read current frame from camera
        ret, frame = self.cap.read()  
        if not ret: return tags
        if self.is_stereo: frame = crop(frame)

        # detect markers in frame, get ids and corners of markers
        #corners, ids, _ = self.detector.detectMarkers(frame)
        corners, ids, _ = cv2.aruco.detectMarkers(
            frame, self.dictionary, parameters=self.parameters
        )

        if corners:  # if there are corners detected
            # use a SubPixel corner refinement method to improve marker detection
            for corner in corners:
                cv2.cornerSubPix(
                    cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY), 
                    np.array(corner[0], dtype='float32'), 
                    WIN_SIZE, ZERO_ZONE, CRITERIA
                )

            # Pose refinement method to improve pose estimation
            rvecs, tvecs, _ = cv2.aruco.estimatePoseSingleMarkers(
                corners, MARKER_SIZE, self.mtx, self.dist
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
                if self.show_gui:  
                    cv2.polylines(  # create vector lines to draw
                        frame, [corners.astype(np.int32)], True, (255, 0, 0), 4, cv2.LINE_4
                    )
                    # draw position vector, position in frame, and distance from camera
                    cv2.drawFrameAxes(frame, self.mtx, self.dist, rvecs[i], tvecs[i], 4, 4)
                    
                    print_text(frame, f'id: {tag.id} Dist: {tag.dist}', tag.tr)
                    print_text(frame, f'Pos: {tag.pos}', tag.br)
            
        # display image if we're debugging
        if self.show_gui: cv2.imshow('Debug camera view', frame)  
        return tags  # return tags found

        
    def __del__(self):
        # release all resources
        self.cap.release()
        cv2.destroyAllWindows()



def main():
    detector = Aruco_Detector(DATA_NAME, show_gui=False)
    start_time = time()

    while True:
        tags = detector.detect_tags()

        # print discovered tags every second
        if time() - start_time > 1:
            start_time = time()
            if len(tags) == 0:
                print('No tags found')
            else: 
                for t in tags: print(f'Tag found: {t}') 

        if cv2.waitKey(1) & 0xFF == ord('q'):  # quit when 'q' is pressed
            break

if __name__ == '__main__':
    main()
