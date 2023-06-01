from yasmin import State
from yasmin.blackboard import Blackboard


class DriveToGpsState(State):
    transitions={'repeat': 'DriveToGps',
                 'next': 'SpiralSearch',
                 'success': 'AddWaypoint',
                 'fail': 'DriveToLastWaypoint',
                 'manual': 'ManualDrive'}

    def __init__(self):
        super().__init__(outcomes=[*DriveToGpsState.transitions])

    def execute(self, blackboar: Blackboard) -> str:
        if False:
            return 'repeat'
        if True:
            return 'next'
        if ...:
            return 'success'
        if ...:
            return 'fail'
        if ...:
            return 'manual'