import time
import adafruit_gps
import serial
import cv2
import numpy as np


# TODO: Change this to find device by name.
uart = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=10)

gps = adafruit_gps.GPS(uart, debug=False)
gps.send_command(b'PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0')
gps.send_command(b'PMTK220,1000')

# Set windows size
windowSize = (1024, 1024)

# Offset origin to center of window
originOffset = (int(windowSize[0] / 2), int(windowSize[1] / 2))

# Create window with black image
cv2.namedWindow("Map", cv2.WINDOW_NORMAL)
img = np.zeros(windowSize, np.uint8)


last_print = time.monotonic()
while True:

    gps.update()

    current = time.monotonic()
    if current - last_print >= 1.0:
        last_print = current
        if not gps.has_fix:
            print('Waiting for fix...')
            continue
        print('=' * 40)  # Print a separator line.
        print('Latitude: {0:.6f} degrees'.format(gps.latitude))
        print('Longitude: {0:.6f} degrees'.format(gps.longitude))
        
        # Convert to pixel coordinates
        
        
        

        # Offset to origin
        lat += originOffset[0]
        long += originOffset[1]

        # Set image pixel to white at current location
        img[lat, long] = 255
        
        cv2.imshow("Map", img)
        
        # Press q to quit  
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

        cv2.waitKey(1)