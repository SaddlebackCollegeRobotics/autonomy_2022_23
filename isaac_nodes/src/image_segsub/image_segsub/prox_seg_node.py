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

# Import the String message type. (Other types are available in the same way.)
from std_msgs.msg import String
from sensor_msgs.msg import Image

import cv2
import cv_bridge

class ProximitySegmentationNode(Node):

    def __init__(self):

        # Give the node a name.
        super().__init__('minimal_publisher')

        self.bridge = cv_bridge.CvBridge()

        # Create left and right camera image publishers
        self.left_image_pub = self.create_publisher(Image, 'prox_seg_node/left_image_rect', 10)
        self.right_image_pub = self.create_publisher(Image, 'prox_seg_node/right_image_rect', 10)

        # Subscribe to left camera image topic
        self.subscription = self.create_subscription(
            Image,
            '/zed2i/zed_node/left/image_rect_color',
            self.publishLeftImage,
            10)
        self.subscription  # prevent unused variable warning

        # Subscribe to right camera image topic
        self.subscription = self.create_subscription(
            Image,
            '/zed2i/zed_node/right/image_rect_color',
            self.publishRightImage,
            10)
        self.subscription  # prevent unused variable warning


    # Resize and format image to work with Proximity Segmentation package
    def format_image(self, msg):
        image = self.bridge.imgmsg_to_cv2(msg, desired_encoding='rgb8')
        cv2.resize(image, (960, 576))
        image = self.bridge.cv2_to_imgmsg(image, encoding='rgb8')
        return image


    # Publish formatted left camera image
    def publishLeftImage(self, msg):
        self.left_image_pub.publish(self.format_image(msg))
    

    # Publish formatted right camera image
    def publishRightImage(self, msg):
        self.right_image_pub.publish(self.format_image(msg))


def main(args=None):
    rclpy.init(args=args)

    prox_seg_node = ProximitySegmentationNode()

    rclpy.spin(prox_seg_node)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    prox_seg_node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
