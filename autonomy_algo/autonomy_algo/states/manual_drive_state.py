from yasmin import State
from yasmin.blackboard import Blackboard


class ManualDriveState(State):
    transitions={'repeat': 'ManualDrive',
                 'next': 'Idle',
                 'manual': 'Dead'}

    def __init__(self):
        super().__init__(outcomes=[*ManualDriveState.transitions])

    def execute(self, blackboard: Blackboard) -> str:
        if False:
            return 'repeat'
        if True:
            return 'next'
        if ...:
            return 'manual'