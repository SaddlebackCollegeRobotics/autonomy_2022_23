# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import numpy as np
import rclpy
from rclpy.node import Node

from stereo_msgs.msg import DisparityImage
from nav_msgs.msg import OccupancyGrid

import cv2
import cv_bridge

class MinimalSubscriber(Node):

    def __init__(self):

        # Give the node a name.
        super().__init__('minimal_subscriber')

        # Subscribe to the topic.
        self.subscription = self.create_subscription(
            DisparityImage,
            'bi3d_node/bi3d_output1111',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

        # Subscribe to the topic.
        self.subscription = self.create_subscription(
            OccupancyGrid,
            'freespace_segmentation/occupancy_grid',
            self.occupancy_grid_callback,
            1)
        self.subscription  # prevent unused variable warning

        self.bridge = cv_bridge.CvBridge()

        # self.timer = self.create_timer(0.01, self.timer_callback)
        self.dropFrame = False


    def timer_callback(self):
        self.dropFrame = False


    # This callback definition simply prints an info message to the console, along with the data it received. 
    def listener_callback(self, msg):
        #cv2.imshow("Image window", self.bridge.imgmsg_to_cv2(msg.image, "rgb8"))
        #cv2.waitKey(1)
        ...
        

    def occupancy_grid_callback(self, msg):

        # get new array from message that removes -1 values
        # if self.dropFrame:
            # return

        # self.dropFrame = True
        new_array = np.array(msg.data)
        
        # create black image
        img = np.zeros((msg.info.height, msg.info.width, 3), np.uint8)

        # set white pixels where there is free space
        for i in range(len(new_array)):
            if new_array[i] == 0:
                img[i//msg.info.width, i%msg.info.width] = 255
        
        # display image
        cv2.imshow("Image window", img)
        cv2.waitKey(1)
        self.get_logger().info('Image received')
        
    
def main(args=None):
    rclpy.init(args=args)

    cv2.namedWindow("Image window", cv2.WINDOW_NORMAL)

    minimal_subscriber = MinimalSubscriber()
    
    rclpy.spin(minimal_subscriber)


if __name__ == '__main__':
    main()
