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

# Ros2 imports
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int64MultiArray

# General imports
import adafruit_gps
import serial


class MinimalPublisher(Node):

    # Initialize publisher
    def __init__(self):

        # Give the node a name.
        super().__init__('minimal_publisher')

        # Initialize and connect to GPS
        self.init_GPS()

        # Specify data type and topic name. Specify queue size (limit amount of queued messages)
        self.publisher_ = self.create_publisher(Int64MultiArray, 'gps_position', 10)

        self.msg = Int64MultiArray()

        # Create a timer that will call the 'timer_callback' function every timer_period second.
        timer_period = 0.5 # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)


    # Initialize and connect to GPS
    def init_GPS(self):

        uart = serial.Serial("/dev/ttyUSB0", baudrate=9600, timeout=10)

        self.gps = adafruit_gps.GPS(uart, debug=False)
        self.gps.send_command(b'PMTK314,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0')
        self.gps.send_command(b'PMTK220,1000')


    def format_data(self, inputNum):
        return int(inputNum * 1000000)


    def timer_callback(self):

        self.gps.update()

        # Wait for satellite connection
        if not self.gps.has_fix:
            self.get_logger().info("Waiting for fix...")
            return

        self.msg.data = [self.format_data(self.gps.latitude), self.format_data(self.gps.longitude)]

        # Publish the message.
        self.publisher_.publish(self.msg)

        # Log the message.
        self.get_logger().info('Publishing: "%s"' % self.msg.data)



def main(args=None):
    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    minimal_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
