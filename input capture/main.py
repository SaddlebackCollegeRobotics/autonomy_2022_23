#import pyjoystick.sdl2 as sdl2
from pyjoystick.sdl2 import Key, Joystick, run_event_loop, sdl2
import time

currentGamepad = None

def print_add(joy):

    global currentGamepad
    currentGamepad = joy

    print(type(joy))
    print('Added', joy)


def print_remove(joy):
    global currentGamepad
    currentGamepad = None

    print('Removed', joy)

    

def key_received(key):
    #print('Key:', key)
    #print(key)
    #print(key.value)
    # if (key.keytype == Key.AXIS): #and key.value > axisDeadZone):
    #     newVal = pyjoystick.deadband(key.value, dead = 0.5, scale=3)
    #     if (newVal != 0):
    #         print(newVal)
    if (key.keytype == Key.BUTTON):
        #print(key.number, '-', key.value)

        if (key.value == 1):
            match key.number:
                case 0:
                    print("A")
                case 1:
                    print("B")
                case 2:
                    print("C")
                case 3:
                    print("D")
                    
            print(currentGamepad)
        



    #if (key == Key.BUTTON):
        #print("down")

#pyjoystick.deadband(val)



def main():
    run_event_loop(print_add, print_remove, key_received)
    
    #mngr = pyjoystick.ThreadEventManager(event_loop=run_event_loop,
                                     #handle_key_event=handle_key_event,
                                     #button_repeater=repeater)




if __name__ == '__main__':
    main()