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

from geometry_msgs.msg import PoseWithCovarianceStamped
from std_msgs.msg import Header

from nav_msgs.msg import Path

import cv2

class MinimalSubscriber(Node):

    def __init__(self):

        # Give the node a name.
        super().__init__('minimal_subscriber')

        # # Subscribe to the topic 'topic'. Callback gets called when a message is received.
        # self.subscription = self.create_subscription(
        #     PoseWithCovarianceStamped,
        #     'visual_slam/tracking/vo_pose_covariance',
        #     self.setPos_callback,
        #     10)
        # self.subscription  # prevent unused variable warning

        # Subscribe to Path topic
        self.subscription = self.create_subscription(
            Path,
            'visual_slam/tracking/slam_path',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning

        # draw the path in opencv
        self.path = Path()
        self.position = (0,0)

    def draw_path(self, msg):

        # draw the path in opencv
        self.path = msg

        # create black image
        img = np.zeros((1024,1024, 3), np.uint8)

        # for first 100 poses
        

        for pose in self.path.poses[-100:]:
            x = pose.pose.position.x
            y = pose.pose.position.y
            
            # multiply by scale
            x = x * 100
            y = y * 100

            # add offset
            x = x + 256
            y = y + 256

            # log x and y
            # self.get_logger().info('x: "%s"' % x)

            # draw rectangle for each pose
            cv2.rectangle(img,(int(x),int(y)),(int(x),int(y)),(0,255,0),1)
            
            # draw rectangle for current position
            #xPos = self.position[0] * 100 + 256
            #yPos = self.position[1] * 100 + 256
            # convert to int
            #xPos = int(xPos)
            #yPos = int(yPos)

            # log x and y
            #self.get_logger().info('xPos: "%s"' % xPos + 'yPos: "%s"' % yPos)

        return img


    # This callback definition simply prints an info message to the console, along with the data it received. 
    def listener_callback(self, msg):
        # draw the path in opencv
        
        # log
        #self.get_logger().info('I heard: "%s"' % msg.header.stamp.sec)

        cv2.imshow("Image window", self.draw_path(msg))
        cv2.waitKey(1)
        
    
    def setPos_callback(self, msg):
        self.position = (msg.pose.pose.position.x, msg.pose.pose.position.y)


def main(args=None):
    rclpy.init(args=args)

    cv2.namedWindow("Image window", cv2.WINDOW_NORMAL)

    minimal_subscriber = MinimalSubscriber()
    
    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
