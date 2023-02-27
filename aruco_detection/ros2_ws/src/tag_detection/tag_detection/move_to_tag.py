import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray
from tag_interface.msg import Tag as TagData
from tag_interface.msg import TagList

from time import perf_counter, sleep


# HYPERPARAMETERS / CONST
TARGET_DIST = 400.0             # cm
DEAD_ZONE = 0.1                 # 0 <= deadzone <= 1
TIME_TO_MOVE_THROUGH_GOAL = 2   # seconds
TIME_OUT = 5                    # seconds


class TagFollower(Node):

    STOP = [0.0, 0.0]
    FORWARD = [-1.0, -1.0]
    SPIN = [-1.0, 1.0]
    MOVE_LEFT = [-0.1, -1.0]
    MOVE_RIGHT = [-1.0, -0.1]

    def __init__(self):
        super().__init__('tag_follower')
        timer_period = 0.1  # seconds

        # INITIALIATIONS
        self.subscription = self.create_subscription(
            TagList, 'autonomy/tag_data', self.listener_callback, 10
        )
        self.subscription  # prevent unsused variable warning

        self.publisher_ = self.create_publisher(
            Float64MultiArray, 'drive/analog_control', 10
        )

        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        self.tags_found = []
        self.curr_dist = float('inf')
        self.time_tag_seen = perf_counter()
        self.is_goalpost = False
        self.moving_through_goal = False
        self.time_goal_move_started = 0


    def listener_callback(self, tag_msg):  # read tag data
        self.tags_found = []
        
        if len(tag_msg.data) >= 1:
            for tag in tag_msg.data:
                self.tags_found.append(tag)


    def timer_callback(self):  # write move instrucitons from tag data        
        move_msg = Float64MultiArray()
        move_msg.data = TagFollower.STOP
        vertices = [move_msg.data[0], move_msg.data[1]]

        # If we see any tags, update current distance and time
        if len(self.tags_found) > 0:
            self.curr_dist = self.tags_found[0].distance
            self.time_tag_seen = perf_counter()

        # If we've reached the goal, stop 
        if self.curr_dist <= TARGET_DIST:
            move_msg.data = TagFollower.STOP
            self.publisher_.publish(move_msg)
            self.print_debug(vertices)
            return

        # If we haven't seen a tag in <timeout> seconds, spin around
        # and look for tag
        if perf_counter() - self.time_tag_seen > TIME_OUT:
            move_msg.data = TagFollower.SPIN
            self.publisher_.publish(move_msg)
            self.print_debug(vertices)
            return

        if len(self.tags_found) == 0: 
            self.print_debug(vertices)
            return

        target_dist_from_center = self.tags_found[0].x_position

        if abs(target_dist_from_center) < DEAD_ZONE:  
            move_msg.data = TagFollower.FORWARD
        elif target_dist_from_center < 0:
            move_msg.data = TagFollower.MOVE_LEFT
        else:
            move_msg.data = TagFollower.MOVE_RIGHT

        self.publisher_.publish(move_msg)


    def print_debug(self, v: list):
        self.get_logger().info(
            f'moving autonomously with velocities ({v[0]}, {v[1]})'
        )



def main(args=None):
    rclpy.init(args=args)
    tag_follower = TagFollower()
    rclpy.spin(tag_follower)

    tag_follower.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()