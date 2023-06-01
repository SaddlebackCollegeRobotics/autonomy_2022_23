import signal
import sys

from typing import Any, Callable

from yasmin import State
from yasmin.blackboard import Blackboard

from ..autonomy_data import *


class IdleState(State):
    transitions={'next': 'DriveToGps',
                 'manual': 'ManualDrive'}

    def __init__(self):
        super().__init__(outcomes=[*IdleState.transitions])

    def execute(self, blackboard: Blackboard) -> str:        
        latitude, longitude, goal_type = (), (), GoalType.GNSS_ONLY
        
        # loop until the user is satisfied with the GPS coordinate entered
        while True:    
            error_msg = '[ERROR] not a valid input\n'

            # Determine if we're entering a coordinate or initiating manual control
            print('[INFO] Knows GPS:')
            for waypoint in blackboard['waypoints']:
                print(f'<Lat: {waypoint.latitude}, Lon: {waypoint.longitude}>')

            print()

            info_msg = '[IDLE] Select an option:\
                        [0] switch to manual drive\
                        [1] enter a GPS coordinate'
            collect_gps = get_input(info_msg, error_msg, lambda: bool(int(input('> '))))
            
            if not collect_gps:
                return 'override'

            # Collect GNSS coordinate input
            prompt = '[IDLE] Enter '
            info_msg = '[IDLE] Enter Latitude (float): '
            latitude = get_input(info_msg, error_msg, lambda: float(input('> ')))
            
            info_msg = '[IDLE] Enter Longitude (float: '
            longitude = get_input(info_msg, error_msg, lambda: float(input('> ')))

            # select type of goal we are navigating to
            options = ''.join([f'\n[{x.value}] {x.name}' for x in GoalType])
            info_msg = '[IDLE] Select a goal type:' + options

            goal_type = get_input(info_msg, error_msg, lambda: GoalType(int(input('> '))))

            # confirm input before we move on
            info_msg = '[IDLE] Select an option:\
                        [0] confirm input\
                        [1] go back'
            go_back = get_input(info_msg, error_msg, lambda: bool(int(input('> '))))
            
            if not go_back:
                break

        # write GPS coorinate and goal type to blackboard, move to next state
        blackboard['goal_type'] = goal_type
        blackboard['target_gps'] = Gps(latitude, longitude)
        return 'next'
    

def get_input(info_msg: str, error_msg: str, input_fn: Callable[[None], Any]) -> Any:
    input_valid = False

    while not input_valid:
        print(info_msg)
        try:
            user_input = input_fn()
            input_valid = True
        except KeyboardInterrupt:
            print('\n[STATUS] program exited safely')
            sys.exit()
        except:
            print(error_msg)

    return user_input
