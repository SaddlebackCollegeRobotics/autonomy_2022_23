from time import time
import cv2
from aruco_dist import Aruco_Detector, Tag

def main():
    detector = Aruco_Detector('logitech_webcam_data.npz', show_gui=False)
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