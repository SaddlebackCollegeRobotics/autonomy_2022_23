from yasmin import State
from yasmin.blackboard import Blackboard


class DriveBetweenGateState(State):
    transitions={'repeat': 'DriveBetweenGate',
                 'success': 'AddWaypoint',
                 'fail': 'DriveToLastWaypoint',
                 'manual': 'ManualDrive'}

    def __init__(self):
        super().__init__(outcomes=[*DriveBetweenGateState.transitions])

    def execute(self, blackboard: Blackboard) -> str:
        if False:
            return 'repeat'
        if True:
            return 'success'
        if ...:
            return 'fail'
        if ...:
            return 'manual'

