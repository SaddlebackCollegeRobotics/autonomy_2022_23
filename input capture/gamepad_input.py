import os
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide" # Hide pygame welcome message
import pygame
import fileinput
import threading


pygame.init()
gamepadDict = {}
loop = True

# Quit program
def quit():
    global loop
    loop = False
    pygame.quit()
    print("Program Terminated")


# Get gamepad object
def getGamepad(id: int):
    if (pygame.joystick.get_count() > 0):
        return pygame.joystick.Joystick(id)
    else:
        return None


# Apply a deadzone to an axis
def applyDeadzone(value: float, deadzone: float):
    if (value < deadzone and value > -deadzone):
        return 0
    else:
        return value


# Get gamepad count
def getGamepadCount():
    return pygame.joystick.get_count()


# Get controller layout from config file
def getGamepadLayout(gamepadName: str):
    
    gamepadLayout = []
    configFound = False
    file = fileinput.input(files ='gamepads.config')

    for line in file:

        if (line == '\n'):
            continue

        if (not configFound):

            if (line == gamepadName + '\n'):
                configFound = True
        else:
            if (line == 'END\n' or line == 'END'):
                break
            else:
                gamepadLayout.append(int(line.split(':')[1].strip()))

    file.close()
    return configFound, gamepadLayout


# Get axis tuples (example: left stick (x, y), right stick (x, y), triggers (l2, r2))
def getAxisGroup(gamepad, deadzone: float, axis_1: int, axis_2: int):

    layout = gamepadDict[gamepad.get_instance_id()][1]
    return applyDeadzone(gamepad.get_axis(layout[axis_1]), deadzone), applyDeadzone(gamepad.get_axis(layout[axis_2]), deadzone)


# Get gamepad left and right triggers (l, r)
def getTriggers(gamepad, deadzone: float):
    return getAxisGroup(gamepad, deadzone, 11, 12)
    

# Get gamepad left stick tuple (x,y)
def getLeftStick(gamepad, deadzone: float):
    return getAxisGroup(gamepad, deadzone, 13, 14)


# Get gamepad right stick tuple (x,y)
def getRightStick(gamepad, deadzone: float):
    return getAxisGroup(gamepad, deadzone, 15, 16)


# Handle new gamepad connections
def onGamepadConnected(event):

    gamepad = getGamepad(event.device_index)

    # Get controller layout from config file
    (configFound, buttonLayout) = getGamepadLayout(gamepad.get_name())

    # Add gamepad and button layout to dictionary
    if (configFound):
        gamepadDict[gamepad.get_instance_id()] = (gamepad, buttonLayout)
        
    else:
        print("Controller Config Not Found!")
    
    print(f"Gamepad {gamepad.get_instance_id()} Connected", end = " | ")
    print(gamepad.get_name())


# Handle gamepad disconnections
def onGamepadRemoved(event):

    if (event.instance_id in gamepadDict.keys()):
        del gamepadDict[event.instance_id]
    
    print(f"Gamepad {event.instance_id} Disconnected")


# Handle gamepad button events
def onButtonEvent(event, callbackList):

    # Grab gamepad layout from dictionary
    layout = gamepadDict[event.instance_id][1]

    # Call function corresponding to button pressed
    for button, callback in zip (layout, callbackList):
        if (event.button == button and callback != None):
            callback()
            break
    

def onHatMotion(event, callbackList):

    # Get gamepad hat
    hat = gamepadDict[event.instance_id][0].get_hat(0)

    # Handle hat DOWN events
    
    if (hat[1] == 1): # North
        callbackList[0]()

    if (hat[1] == -1): # South
        callbackList[1]()

    if (hat[0] == -1): # West
        callbackList[2]()

    if (hat[0] == 1): # East
        callbackList[3]()

    # Handle hat UP events

    if (hat[0] == 0 and hat[1] == 0): # Hat is centered
        callbackList[4]()
    

# Takes in an array of callback functions
def getButtonCallbacks(onButtonDownEvents, onButtonUpEvents, hatEvents):

    def async_wrapper():
    
        while loop:
            
            # Handle events
            for event in pygame.event.get():

                # Handle quit event
                if event.type == pygame.QUIT:
                    quit()
                    break

                # Get Button DOWN gamepad events
                if event.type == pygame.JOYBUTTONDOWN:
                    onButtonEvent(event, onButtonDownEvents)

                # Get Button UP gamepad events
                if event.type == pygame.JOYBUTTONUP:
                    onButtonEvent(event, onButtonUpEvents)
                    
                # Handle gamepad hat buttons
                if event.type == pygame.JOYHATMOTION:
                    onHatMotion(event, hatEvents)

                # Handle new gamepad connections
                if event.type == pygame.JOYDEVICEADDED:
                    onGamepadConnected(event)

                # Handle gamepad disconnections
                if event.type == pygame.JOYDEVICEREMOVED:
                    onGamepadRemoved(event)
        

    thread = threading.Thread(target=async_wrapper)
    thread.start()