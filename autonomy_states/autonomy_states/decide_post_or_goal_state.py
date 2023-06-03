from yasmin import State
from yasmin.blackboard import Blackboard


class DecidePostOrGateState(State):
    transitions={'post': 'DriveToPost',
                'gate': 'DriveBetweenGate'} 

    def __init__(self):
        super().__init__(outcomes=[*DecidePostOrGateState.transitions])

    def execute(self, blackboard: Blackboard) -> str:
        if True:
            return 'post'
        if ...:
            return 'gate'
