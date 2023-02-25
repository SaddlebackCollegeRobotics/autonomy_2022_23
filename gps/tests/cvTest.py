import cv2
import numpy as np

# Set windows size
windowSize = (1024, 1024)

# Create window
cv2.namedWindow("Map", cv2.WINDOW_NORMAL)

# Create black image
img = np.zeros(windowSize, np.uint8)

# Create array of random points
points = np.random.randint(0, 1024, (100, 2))
index = 0

while True:
    cv2.imshow("Map", img)

    # Set image pixel to white at current location
    img[points[index][0], points[index][1]] = 255
    index += 1

    # Press q to quit  
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

    cv2.waitKey(1)