import rclpy
from rclpy.node import Node
from std_msgs.msg import Float64MultiArray

class DummyDriver(Node):
    def __init__(self):
        super().__init__('dummy_driver')
        self.subscription = self.create_subscription(Float64MultiArray, 'drive/analog_control', self.listener_callback, 10)
        self.subscription  # prevent unsused variable warning

    def listener_callback(self, msg):
        left_vel, right_vel = msg.data

        msg_str = ''
        if left_vel == right_vel:
            msg_str = 'stop moving' if left_vel == 0 else 'move straight'
        elif left_vel < right_vel:
            msg_str = 'move left'
        elif left_vel > right_vel:
            msg_str = 'move right'

        self.get_logger().info(msg_str)


def main(args=None):
    rclpy.init(args=args)
    subscriber = DummyDriver()
    rclpy.spin(subscriber)

    subscriber.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()