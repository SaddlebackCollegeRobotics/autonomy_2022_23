import rclpy

from std_msgs.msg import Int32
from geometry_msgs.msg import Twist

from simple_node import Node
from yasmin.blackboard import Blackboard
from yasmin import StateMachine
from yasmin_viewer import YasminViewerPub

from .states.add_waypoint_state import AddWaypointState
from .states.dead_state import DeadState
from .states.decide_post_or_goal_state import DecidePostOrGateState
from .states.drive_between_gates_state import DriveBetweenGateState
from .states.drive_to_gps_state import DriveToGpsState
from .states.drive_to_last_waypoint_state import DriveToLastWaypointState
from .states.drive_to_post_state import DriveToPostState
from .states.idle_state import IdleState
from .states.manual_drive_state import ManualDriveState
from .states.spiral_search_state import SpiralSearchState

from tag_interface.action import DriveToGps, SpiralSearch, DriveToMarker


class AutonomyAlgorithm(Node):

    #TODO fix ROS node interfacing
    def __init__(self, gui: bool = False):
        """ Create ROS I/O resources for autonomy state machine """

        super().__init__('autonomy_algo')

        self._gui = gui

        # Blackboard to hold ROS resources
        self._blackboard = Blackboard()

        # Publishers
        self._blackboard['rover_controller'] = \
            self.create_publisher(Twist, '/cmd_vel', 10)        
        self._blackboard['led_controller'] = self.create_publisher(Int32, 10)

        # Action Clients
        self._blackboard['drive_to_gps_client'] = \
            self.create_action_client(DriveToGps, feedback_cb=self._drive_rover)
        self._blackboard['spiral_search_client'] = \
            self.create_action_client(SpiralSearch, feedback_cb=self._drive_rover)
        self._blackboard['drive_to_marker_client'] = \
            self.create_action_client(DriveToMarker, feedback_cb=self._drive_rover)

    def _drive_rover(self, feedback_msg):
        feedback = feedback_msg.feedback
        self.get_logger().info(
            f'Received feedback 👽: Linear: {feedback.cmd_vel.linear.x}, \
                Angular: {feedback.cmd_vel.angular.z}');
    
        self.self._blackboard['rover_controller'].publish(feedback.cmd_vel)

    def _build_state_machine(self):
        """Build autonomy state machine (asm)

        s = {'Idle', 'DriveToGps', 'SpiralSearch', 'DecidePostOrGate', 
             'DriveToPost', 'DriveBetweenGate', 'AddWaypoint', 
             'DriveToLastWaypoint', 'ManualDrive', 'Dead'}

        l = {'repeat', 'back', 'next', 'success', 'fail', 'manual', 'post', 
             'gate', 'dead'}
        """
        self.asm = StateMachine(outcomes=['dead'])

        # S_0, always start by adding starting point to known waypoints
        self.asm.add_state('AddWaypoint', AddWaypointState(),
                transitions=AddWaypointState.transitions)
        self.asm.add_state('Idle', IdleState(), 
                      transitions=IdleState.transitions)
        self.asm.add_state('DriveToGps', DriveToGpsState(), 
                      transitions=DriveToGpsState.transitions)
        self.asm.add_state('SpiralSearch', SpiralSearchState(), 
                      transitions=SpiralSearchState.transitions)
        self.asm.add_state('DecidePostOrGate', DecidePostOrGateState(),
                      transitions=DecidePostOrGateState.transitions)
        self.asm.add_state('DriveToPost', DriveToPostState(),
                      transitions=DriveToPostState.transitions)
        self.asm.add_state('DriveBetweenGate', DriveBetweenGateState(),
                      transitions=DriveBetweenGateState.transitions)
        self.asm.add_state('DriveToLastWaypoint', DriveToLastWaypointState(),
                      transitions=DriveToLastWaypointState.transitions)
        self.asm.add_state('ManualDrive', ManualDriveState(),
                      transitions=ManualDriveState.transitions)
        self.asm.add_state('Dead', DeadState())

        if self._gui:
            YasminViewerPub(self, 'AUTONOMY_STATE_MACHINE', self.asm)
        
        self.asm(self._blackboard)  # execute


def main(args=None):
    rclpy.init(args=args)
    node = AutonomyAlgorithm()
    node.join_spin()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
