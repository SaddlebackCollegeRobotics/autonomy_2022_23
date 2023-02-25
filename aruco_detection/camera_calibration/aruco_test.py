import cv2
import os
import sys
from time import time

sys.path.insert(0, f'{os.getcwd()}/../ros2_ws/src/tag_detection/tag_detection')

from aruco_detector import *

DATA_NAME = 'macbook_data.npz'
DATA_DIR = f'{os.getcwd()}'

def main():
    detector = Aruco_Detector(DATA_NAME, DATA_DIR, show_gui=False)
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
