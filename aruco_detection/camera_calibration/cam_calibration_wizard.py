'''
CAMERA CALIBRATION WIZARD
-------------------------
utility for generating camera matrix and distortion coefficients
used by OpenCV object detection. To use, run python file. Open 
the first window created by python and select your camera,
then return to the terminal to edit settings, and finally
return to python window to take calibration photos
'''
import cv2 as cv
import glob
import numpy as np
import os

rows, cols = 7, 6
min_photos = 13  # minimum photos to calibrate camera
num_cams_to_check = 50  # number of cameras to try before giving up
input_folder = './input/'
data_folder = './calibration_data/'
device_name = 'default'


# helper function to simplify cropping photo
def crop(image):
    return image[0:image.shape[0], 0:image.shape[1]//2]

# helper function to simplify writing text to screen
def write_text(image, text, position):
    cv.putText(image, text, position, cv.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2, cv.LINE_AA)

# take photos used in calibration
def take_photos():
    device_number = 0
    camera_found = False
    
    global device_name
    device_name = input('Enter device name: ')
    is_stereo = True if input('is this a stereoscopic camera? (y/n): ').upper() == 'Y' else False

    while device_number < num_cams_to_check and not camera_found:
        test_cap = cv.VideoCapture(device_number)
        if not test_cap.isOpened(): continue
        
        while True:
            _, test_frame = test_cap.read()
            write_text(test_frame, 'press "y" if this is the correct camera, or "n" otherwise', (20, 30))
            cv.imshow('Choose Camera', test_frame)

            keypress = cv.waitKey(1) & 0xFF 
            if keypress == ord('y'): 
                camera_found = True
                break
            elif keypress == ord('n'): 
                device_number += 1
                break

        test_cap.release()
        cv.destroyAllWindows()


    cap = cv.VideoCapture(0)
    if not cap.isOpened():
        print('no camera devices found')
        return False

    photos_taken = 0

    if not os.path.exists(f'{input_folder}{device_name}'):
        os.makedirs(f'{input_folder}{device_name}')

    while True:
        _, frame = cap.read()
        if is_stereo: frame = crop(frame)

        displayed_frame = frame.copy()
        write_text(displayed_frame, 'Please photograph checkerboard from different angles', (20, 30))
        write_text(displayed_frame, 'Press "space" to capture image, or "q" to quit when finished', (20, 60))
        write_text(displayed_frame, f'{min_photos - photos_taken if photos_taken < min_photos else 0} photos left to be taken', (20, 90))

        cv.imshow('Camera Calibration Wizard', displayed_frame)

        keypress = cv.waitKey(1) & 0xFF 
        if keypress == ord(' '):  # take photo when 'space' is pressed
            cv.imwrite(f'{input_folder}{device_name}/{photos_taken}.png', frame)
            photos_taken += 1

        elif keypress == ord('q') and photos_taken >= min_photos:  # quit when 'q' is pressed
            break

    # release all resources
    cap.release()
    cv.destroyAllWindows()
    print('images taken successfully')
    return True


def calibrate():
    ###SETUP BOARDS#############################################################
    print('starting camera calibration...')
    # termination criteria
    criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 30, 0.001)


    # prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
    objp = np.zeros((cols*rows,3), np.float32)
    objp[:,:2] = np.mgrid[0:rows,0:cols].T.reshape(-1,2)

    # Arrays to store object points and image points from all the images.
    objpoints = [] # 3d point in real world space
    imgpoints = [] # 2d points in image plane.

    images = glob.glob(f'{input_folder}{device_name}/*.png')

    if len(images) == 0:
        print('no images found, camera not calibrated')
        return

    for fname in images:
        img = cv.imread(fname)
        gray = cv.cvtColor(img,cv.COLOR_BGR2GRAY)

        # Find the chess board corners
        ret, corners = cv.findChessboardCorners(gray, (rows,cols),None)

        # If found, add object points, image points (after refining them)
        if ret == True:
            objpoints.append(objp)

            corners2 = cv.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
            imgpoints.append(corners2)

            # Draw and display the corners
            img = cv.drawChessboardCorners(img, (rows,cols), corners2,ret)
            #cv.imshow('img',img)
            #cv.waitKey(500)

    cv.destroyAllWindows()

    ###CAMERA CALIBRATION#######################################################
    # ret -> return value
    # mtx -> camera matrix
    # dist -> distortion coefficients
    # rvecs -> rotation vectors
    # tvecs -> translation vectors
    ret, mtx, dist, rvecs, tvecs = cv.calibrateCamera(objpoints, imgpoints, gray.shape[::-1], None, None)

    ###RE-PROJECTION ERROR######################################################
    mean_error = 0
    for i in range(len(objpoints)):
        imgpoints2, _ = cv.projectPoints(objpoints[i], rvecs[i], tvecs[i], mtx, dist)
        error = cv.norm(imgpoints[i],imgpoints2, cv.NORM_L2)/len(imgpoints2)
        mean_error += error

    print(F"total error:  {mean_error/len(objpoints)}")

    ###SAVE CALIBRATION DATA####################################################
    np.savez(f'{data_folder}{device_name}_data.npz',mtx=mtx,dist=dist,rvecs=rvecs,tvecs=tvecs)
    print('data saved successfully to file')


if __name__ == '__main__':
    if take_photos(): calibrate()
    