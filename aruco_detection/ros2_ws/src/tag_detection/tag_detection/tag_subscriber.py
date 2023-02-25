import rclpy
from rclpy.node import Node

from tag_interface.msg import Tag as Tag_msg
from tag_interface.msg import Coordinate

class TagSubscriber(Node):
    def __init__(self):
        super().__init__('tag_subscriber')
        self.subscription = self.create_subscription(Tag_msg, 'autonomy/tag_data', self.listener_callback, 10)
        self.subscription  # prevent unsused variable warning

    def listener_callback(self, tag_msg):
        if len(tag_msg.id) < 1:
            self.get_logger().info('No tags found')
        else:
            self.get_logger().info('Tags found:')

            # I'm sorry this is disgusting
            for id, top_right, top_left, bottom_right, bottom_left, position, distance in zip(tag_msg.id, tag_msg.top_right, tag_msg.top_left, tag_msg.bottom_right, tag_msg.bottom_left, tag_msg.position, tag_msg.distance):    
                self.get_logger().info(f'id: {id}')
                self.get_logger().info(f'\ttop right:    {top_right}')
                self.get_logger().info(f'\ttop left:     {top_left}')
                self.get_logger().info(f'\tbottom right: {bottom_right}')
                self.get_logger().info(f'\tbottom left:  {bottom_left}')
                self.get_logger().info(f'\tposition:     {position}')
                self.get_logger().info(f'\tdistance:     {distance}')


def main(args=None):
    rclpy.init(args=args)

    tag_subscriber = TagSubscriber()

    rclpy.spin(tag_subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    tag_subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()