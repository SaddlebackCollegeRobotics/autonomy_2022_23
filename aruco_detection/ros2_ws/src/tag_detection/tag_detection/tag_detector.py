# install opencv dependencies first:
# pip3 install opencv-python
# pip3 install opencv-contrib-python
from collections import namedtuple
import cv2 as cv
import numpy as np

import rclpy
from rclpy.node import Node
from Tag.msg import Tag


# toggle for showing image to help with debugging
DEBUG = False

# MARKER
# NOTE make sure to run camera calibration before using, and have 
# correct filename here
CAM_DATA = 'macbook_data.npz'  
TAG_SIZE = 14.7  # cm
ARUCO_DICT = cv.aruco.DICT_4X4_50

# for detection of markers in subpixels
# we search for subpixels inside window and outside zero zone
WIN_SIZE = (5, 5)
ZERO_ZONE = (-1, -1)
# criteria specifies desired accuracy, number of iterations, and termination criteria
# https://docs.opencv.org/4.x/d9/d5d/classcv_1_1TermCriteria.html
CRITERIA = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_COUNT, 40, 0.001)


# TEXT
FONT_SCALE = 1
FONT_THICK = 2

# COLORS
BLUE = (255, 0, 0)
GREEN = (0, 255, 0)

class TagDetector(Node):
    
    def __init__(self):
        # ROS2 NODE 
        # Tune timer until tag detection does not lag behind camera
        timer_period = 0.01  # seconds
        super().__init__('tag_detector')
        self.publisher_ = self.create_publisher(Tag, 'tag_data', 10)
        self.timer = self.create_timer(timer_period, self.timer_callback)
        ...

        # OPENCV 
        # load calibration data from numpy file
        with np.load(f'./data/{CAM_DATA}') as X:
            self.mtx, self.dist, _ , _ = [X[i] for i in ('mtx','dist','rvecs','tvecs')]

        # define aruco tag dictionary, tag detection parameters, 
        # and video capture feed for tag detection
        self.tag_dict = cv.aruco.Dictionary_get(ARUCO_DICT)
        self.tag_params = cv.aruco.DetectorParameters_create()
        self.cap = cv.VideoCapture(0)

    def __del__(self):
        self.cap.release()
        cv.destroyAllWindows()

    def timer_callback(self):
        # create set to store ids for discovered tags, and list to hold tag data
        tag_ids = set()
        tags = []  

        # read current frame from camera and convet to grayscale
        _, frame = self.cap.read()  
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)

        # detect tags in frame, get ids and corners of tags
        corner_list, ids, _ = cv.aruco.detectMarkers(
            frame, self.marker_dict, parameters=self.marker_params
        )

        if corner_list:  # if there are corners detected
              # use a SubPixel corner refinement method to improve tag detection
            for corner in corner_list:
                cv.cornerSubPix(
                    gray, np.array(corner[0], dtype='float32'), WIN_SIZE, ZERO_ZONE, CRITERIA
                )

            # estimate pose of tag using known size and camera data
            rvecs, tvecs, _ = cv.aruco.estimatePoseSingleMarkers(
                corner_list, TAG_SIZE, self.mtx, self.dist
            )

            # loop through tags and package data
            for tag_id, corners, i in zip(ids, corner_list, range(0, ids.size)):
                # clean corner data and package as a single tuple
                clean_corners = corners.reshape(4, 2).astype(int) 
                tag = self.Tag(
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
                    cv.drawFrameAxes(frame, self.mtx, self.dist, rvecs[i], tvecs[i], 4, 4)
                    cv.putText(frame, f'id: {tag.id} Dist: {tag.dist}', tag.tr, cv.FONT_HERSHEY_SIMPLEX, FONT_SCALE, GREEN, FONT_THICK, cv.LINE_AA)
                    cv.putText(frame, f'Pos: {tag.pos}', tag.br, cv.FONT_HERSHEY_SIMPLEX, FONT_SCALE, GREEN, FONT_THICK, cv.LINE_AA)

        if DEBUG: cv.imshow('frame', frame)  # display image if we're debugging

        ...
        # Send data to ROS2 topic and info log
        msg = String()
        msg.data = 'Hello World'
        self.publisher_.publish(msg)
        
        # log result of tag detection
        log = ''
        if len(tags == 0):
            log = 'No tags found'
        else:
            for t in tags: log += f'Tag found: {t}\n' 

        self.get_logger().info(log)



def main(args=None):
    rclpy.init(args=args)

    tag_detector = TagDetector()

    rclpy.spin(tag_detector)

    # Destroy the node emplicitly, otherwise garbage collected
    tag_detector.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
