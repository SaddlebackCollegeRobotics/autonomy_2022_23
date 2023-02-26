import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

import numpy as np
import cv2


class Tag_Visualizer(Node):
    
    def __init__(self):
        super().__init__('tag_visualizer')

        self.subscription = self.create_subscription(Image, 'autonomy/tag_visualization', self.listener_callback, 10)
        self.bridge = CvBridge()

        self.get_logger().info('tag_visualizer node started')


    def listener_callback(self, image_msg):
        frame = self.bridge.imgmsg_to_cv2(image_msg)
        cv2.imshow('tag orientation visualization', frame)

        self.get_logger().info('diaplaying image')

def main(args=None):
    rclpy.init(args=args)
    tag_visualizer = Tag_Visualizer()
    rclpy.spin(tag_visualizer)

    tag_visualizer.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()