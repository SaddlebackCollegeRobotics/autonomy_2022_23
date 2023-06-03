from yasmin import State
from yasmin.blackboard import Blackboard


class DriveToLastWaypointState(State):
    transitions={'repeat': 'DriveToLastWaypoint',
                 'success': 'Idle',
                 'fail': 'ManualDrive',
                 'manual': 'ManualDrive'}

    def __init__(self):
        super().__init__(outcomes=[*DriveToLastWaypointState.transitions])

    def execute(self, blackboard: Blackboard) -> str:
        if False:
            return 'repeat'
        if True:
            return 'success'
        if ...:
            return 'fail'
        if ...:
            return 'manual'
