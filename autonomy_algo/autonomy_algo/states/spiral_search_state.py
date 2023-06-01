from yasmin import State
from yasmin.blackboard import Blackboard


class SpiralSearchState(State):
    transitions={'repeat': 'SpiralSearch',
                 'success': 'DecidePostOrGate',
                 'fail': 'DriveToLastWaypoint',
                 'manual': 'ManualDrive'}

    def __init__(self):
        super().__init__(outcomes=[*SpiralSearchState.transitions])

    def execute(self, blackboard: Blackboard) -> str:
        if False:
            return 'repeat'
        if True:
            return 'success'
        if ...:
            return 'fail'
        if ...:
            return 'manual'