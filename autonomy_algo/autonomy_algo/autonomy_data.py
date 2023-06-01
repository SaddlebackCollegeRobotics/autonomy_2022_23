from enum import Enum
from typing import NamedTuple


class GoalType(Enum):
    GNSS_ONLY = 0
    POST = 1
    GOAL = 2


class Angle(NamedTuple):
    degrees: int
    minutes: int
    seconds: int


class Gps(NamedTuple):
    latitude: Angle
    longitude: Angle
