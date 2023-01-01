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

import rclpy
from rclpy.node import Node

from std_msgs.msg import String
from sensor_msgs.msg import Image

import cv2
import cv_bridge

class MinimalSubscriber(Node):

    def __init__(self):

        # Give the node a name.
        super().__init__('minimal_subscriber')

        self.bridge = cv_bridge.CvBridge()

        # Subscribe to the topic 'topic'. Callback gets called when a message is received.
        self.subscription = self.create_subscription(
            Image,
            '/zed2i/zed_node/left/image_rect_color',
            self.listener_callback,
            10)
        self.subscription  # prevent unused variable warning


    # This callback definition simply prints an info message to the console, along with the data it received. 
    def listener_callback(self, msg):
        #self.get_logger().info(str(msg.header.stamp.sec) + "." + str(msg.header.stamp.nanosec) + " " + str(msg.header.frame_id))
        frame = self.bridge.imgmsg_to_cv2(msg, "bgr8")
        self.get_logger().info(str(msg.header.stamp.sec) + "." + str(msg.header.stamp.nanosec) + " " + str(msg.header.frame_id))
        cv2.imshow("Image RGB", frame)
        cv2.waitKey(3)


def main(args=None):
    rclpy.init(args=args)

    cv2.namedWindow("Image RGB", cv2.WINDOW_NORMAL)

    minimal_subscriber = MinimalSubscriber()
    rclpy.spin(minimal_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
