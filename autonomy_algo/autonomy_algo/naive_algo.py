import rclpy
from rclpy.node import Node

from tag_interface.msg import AutonomyCommand, GpsList

from autonomy_states.idle_state import IdleState
from autonomy_states.drive_to_gps_state import DriveToGpsState
from autonomy_states.spiral_search_state import SpiralSearchState
# from autonomy_states.drive_to_post_state import DriveToPostState
# from autonomy_statees.drive_between_gates_state import DriveBetweenGatesState
from autonomy_states.data import GoalType

class NaiveAutonomyAlgo(Node):

    def __init__(self):
        super().__init__('naive_algo')
        self.known_waypoints = []

        self.idle = IdleState()
        self.drive_to_gps = DriveToGpsState()
        self.spiral_search = SpiralSearchState()
        self.drive_to_post = DriveToPostState()
        self.drive_between_gates_state = DriveBetweenGatesState()
        
        print('created states')

        self.execute_algo()

    def execute_algo(self):
        print('executing state')
        blackboard = {'waypoints':[]}
        transition = self.idle.execute(blackboard)

        if transition == 'next':
            transition = self.drive_to_gps.execute(blackboard)

            if transition == 'next':
                transition = self.spiral_search.execute(blackboard)  

                if transition == 'post':
                    self.drive_to_post.execute(blackboard)
                elif transition == 'gate':
                    self.drive_to_post.execute(blackboard)


def main(args=None):
    rclpy.init(args=args)
    node = NaiveAutonomyAlgo()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()
