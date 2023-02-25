import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

class DummyDriver(Node):
    def __init__(self):
        super().__init__('dummy_driver')
        self.subscription = self.create_subscription(Float64MultiArray, 'drive/analog_control', self.listener_callback, 10)
        self.subscription  # prevent unsused variable warning

    def listener_callback(self, msg):
        self.get_logger().info(f'left vel: {msg.left_vel}, right vel: {msg.right_vel}')

def main(args=None):
    rclpy.init(args=args)

    subscriber = DummyDriver()
    rclpy.spin(subscriber)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()