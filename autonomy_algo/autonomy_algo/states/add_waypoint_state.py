from yasmin import State
from yasmin.blackboard import Blackboard

from ..autonomy_data import *


class AddWaypointState(State):
    transitions={'next': 'Idle'}

    def __init__(self):
        super().__init__(outcomes=[*AddWaypointState.transitions])
        self._gps_subsciber = self.create_

    def execute(self, blackboard: Blackboard) -> str:
        curr_gps = Gps((0, 0, 0), (0, 0, 0))  #TODO get current gps from GPS pub
        
        if 'waypoints' in blackboard:
            blackboard['waypoints'].append(curr_gps)
        else:
            blackboard['waypoints'] = [curr_gps]

        return 'next'
