import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from tag_interface.msg import Tag as TagData
from tag_interface.msg import TagList

from time import perf_counter


# HYPERPARAMETERS / CONST
TARGET_DIST = 200.0             # any measurement unit
DEAD_ZONE = 0.1                 # 0 <= deadzone <= 1
TIME_TO_MOVE_THROUGH_GOAL = 2   # seconds
TIME_OUT = 5                    # seconds


class TagFollower(Node):

    def __init__(self):
        super().__init__('tag_follower')

        self.subscription = self.create_subscription(
            TagList, 'autonomy/tag_data', self.listener_callback, 10
        )

        self.publisher_ = self.create_publisher(
            Twist, 'drive/cmd_vel', 10
        )

        self.curr_dist = float('inf')
        self.time_tag_seen = perf_counter()
        self.twist_msg = Twist()

    def listener_callback(self, tag_msg):
        tags_found = tag_msg.data

        # If we see any tags, update current distance and time
        if len(tags_found) > 0:
            self.curr_dist = tags_found[0].distance
            self.time_tag_seen = perf_counter()

        # If we've reached the goal, stop
        if self.curr_dist <= TARGET_DIST:
            self.twist_msg.linear.x = 0.0
            self.twist_msg.angular.z = 0.0

        # If we haven't seen a tag in <timeout> seconds, spin around
        # and look for tag
        elif perf_counter() - self.time_tag_seen > TIME_OUT:
            self.twist_msg.linear.x = 0.0
            self.twist_msg.angular.z = 1.0

        # If we see any tags right now, update velocity
        elif len(tags_found) > 0:
            target_dist_from_center = tags_found[0].x_position

            if abs(target_dist_from_center) < DEAD_ZONE:
                self.twist_msg.linear.x = 1.0
                self.twist_msg.angular.z = 0.0
            elif target_dist_from_center < 0:
                self.twist_msg.linear.x = 0.2
                self.twist_msg.angular.z = 1.0
            else:
                self.twist_msg.linear.x = 1.0
                self.twist_msg.angular.z = 0.2

        self.publisher_.publish(self.twist_msg)
        self.print_debug()

    def print_debug(self):
        self.get_logger().info(
            f'Moving autonomously with linear.x: {self.twist_msg.linear.x}, angular.z: {self.twist_msg.angular.z}'
        )


def main(args=None):
    rclpy.init(args=args)
    tag_follower = TagFollower()
    rclpy.spin(tag_follower)

    tag_follower.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
