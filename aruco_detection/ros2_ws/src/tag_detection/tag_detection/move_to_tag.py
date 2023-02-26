import rclpy
from rclpy.node import Node

from std_msgs.msg import Float64MultiArray
from tag_interface.msg import Tag as TagData
from tag_interface.msg import TagList

class TagFollower(Node):
    def __init__(self):
        super().__init__('tag_follower')
        # HYPERPARAMETERS
        self.target_dist = 200  # cm
        self.deadzone = 0.1  # 0 <= deadzone <= 1
        timer_period = 0.1

        # INITIALIATIONS
        self.subscription = self.create_subscription(TagList, 'autonomy/tag_data', self.listener_callback, 10)
        self.subscription  # prevent unsused variable warning

        self.publisher_ = self.create_publisher(Float64MultiArray, 'drive/analog_control', 10)
        self.timer = self.create_timer(timer_period, self.timer_callback)
        
        self.tags_found = []
        self.img_length = 0


    def listener_callback(self, tag_msg):  # read tag data
        self.tags_found = []
        
        if len(tag_msg.data) < 1:
            self.get_logger().info('No tags found')
        else:
            self.get_logger().info(f'Tag ids found: {[tag.id for tag in tag_msg.data]}')

            for tag in tag_msg.data:
                self.tags_found.append(tag)


    def timer_callback(self):  # write move instrucitons from tag data
        move_msg = Float64MultiArray()
        move_msg.data = [0.0, 0.0]

        # if we don't see any tags, stop
        if len(self.tags_found) == 0:
            self.publisher_.publish(move_msg)
            return

        #if we've hit the minimum distance, stop
        if self.tags_found[0].distance <= self.target_dist:
            self.publisher_.publish(move_msg)
            return
        
        target_dist_from_center = 0

        if len(self.tags_found) == 1:  # if we found 1 tag (sign post)
            target_dist_from_center = self.tags_found[0].x_position
        elif len(self.tags_found) > 1:  # if we found 2 tag (goal post)
            target_dist_from_center = (self.tags_found[0].x_position + self.tags_found[1].x_position) 

        # if we are looking at center, drive forward
        if abs(target_dist_from_center) < self.deadzone:  
            move_msg.data[0], move_msg.data[1] = 1.0, 1.0
            self.publisher_.publish(move_msg)
            return
        
        # turn left if target dist is left, turn right if target dist is right
        move_msg.data[0] = 1.0 if target_dist_from_center > 0 else 0.5
        move_msg.data[1] = 1.0 if target_dist_from_center < 0 else 0.5

        self.publisher_.publish(move_msg)

                           

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