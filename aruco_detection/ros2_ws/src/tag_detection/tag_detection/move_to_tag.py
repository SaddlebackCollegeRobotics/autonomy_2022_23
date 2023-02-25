from collections import namedtuple
import math

import rclpy
from rclpy.node import Node

from tag_interface.msg import Tag as Tag_msg
from tag_interface.msg import Coordinate
from std_msgs.msg import Float64MultiArray

Tag = namedtuple('Tag', ['id', 'tr', 'tl', 'br', 'bl', 'pos', 'dist'])


class TagFollower(Node):
    def __init__(self):
        super().__init__('tag_subscriber')
        self.subscription = self.create_subscription(Tag_msg, 'autonomy/tag_data', self.listener_callback, 10)
        self.subscription  # prevent unsused variable warning

        self.publisher_ = self.create_publisher(Float64MultiArray, 'drive/analog_control', 10)
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        self.tags_found = []
        self.image_len = 0

        self.target_dist = 200  # cm



    def timer_callback(self):  # write move instrucitons from tag data
        move_msg = Float64MultiArray()

        # if we've hit the minimum distance, stop
        if self.tags_found[0].dist <= self.target_dist:
            move_msg.left_vel, move_msg.right_vel = 0.0, 0.0
            self.publisher_.publish(move_msg)
            return
        
        if len(self.tags_found) == 1:  # if we found 1 tag (sign post)
            target_dist_from_center = self.tags_found[0].pos
        elif len(self.tags_found) > 1:  # if we found 2 tag (goal post)
            target_dist_from_center = (self.tags_found[0].pos + self.tags_found[1].pos) 

        # if we are looking at center, drive forward
        if math.abs(target_dist_from_center) < 5:  
            move_msg.left_vel, move_msg.right_vel = 1.0, 1.0
            self.publisher_.publish(move_msg)
            return
        
        # turn left if target dist is left, turn right if target dist is right
        move_msg.left_vel = 1.0 if target_dist_from_center > 0 else 0.5
        move_msg.right_vel = 1.0 if target_dist_from_center < 0 else 0.5

        self.publisher_.publish(move_msg)

            

    def listener_callback(self, tag_msg):  # read tag data
        self.tags_found = []
        
        if len(tag_msg.id) < 1:
            self.get_logger().info('No tags found')
        else:
            self.get_logger().info('Tags found:')

            self.image_len = tag_msg.image_len

            # I'm sorry this is disgusting
            for id, top_right, top_left, bottom_right, bottom_left, position, distance in zip(tag_msg.id, tag_msg.top_right, tag_msg.top_left, tag_msg.bottom_right, tag_msg.bottom_left, tag_msg.position, tag_msg.distance):    
                self.tags_found.append( Tag(id, top_right, top_left, bottom_right, bottom_left, position, distance))
                
                self.get_logger().info(f'id: {id}')
                self.get_logger().info(f'\ttop right:    {top_right}')
                self.get_logger().info(f'\ttop left:     {top_left}')
                self.get_logger().info(f'\tbottom right: {bottom_right}')
                self.get_logger().info(f'\tbottom left:  {bottom_left}')
                self.get_logger().info(f'\tposition:     {position}')
                self.get_logger().info(f'\tdistance:     {distance}')


def main(args=None):
    rclpy.init(args=args)

    tag_follower = TagFollower()
    rclpy.spin(tag_follower)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    tag_follower.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()