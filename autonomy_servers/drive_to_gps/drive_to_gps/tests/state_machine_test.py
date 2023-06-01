#TODO Cam needs to finish
import rclpy
from rclpy.action import ActionServer
from rclpy.node import Node

from tag_interface.action import DriveToGps


class DriveToGpsActionServer(Node):

    def __init__(self):
        super().__init__('drive_to_gps_action_server')

        self._action_server = ActionServer(
            self,
            DriveToGps,
            'drive_to_gps',
            self._execute_callback)
        
    def _execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal... 🤔')

        feedback_vel_msg = DriveToGps.Feedback()
        feedback_vel_msg.cmd_vel = [1.0, 1.0]
