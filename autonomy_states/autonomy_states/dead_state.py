from yasmin import State
from yasmin.blackboard import Blackboard


class DeadState(State):
    def __init__(self):
        super().__init__(outcomes=['dead'])

    def execute(self, blackboard: Blackboard) -> str:
        ...
        return 'dead'