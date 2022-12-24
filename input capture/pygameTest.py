import os

# Hide pygame welcome message
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"

import pygame
import fileinput

pygame.init()
gamepadDict = {}


# Get controller layout from config file
def getGamepadLayout(gamepadName):
    
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


# Handle new gamepad connections
def onGamepadConnected(event):
    gamepad = pygame.joystick.Joystick(event.device_index)

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


# Handle gamepad onButtonDown events
def onButtonDown(event):

    # Grab gamepad layout from dictionary
    layout = gamepadDict[event.instance_id][1]

    # North
    if event.button == layout[0]:
        print("North")

    # West
    if event.button == layout[1]:
        print("West")

    # South
    if event.button == layout[2]:
        print("South")

    # East
    if event.button == layout[3]:
        print("East")
    
    # Share
    if event.button == layout[4]:
        print("Share")

    # Options
    if event.button == layout[5]:
        print("Options")

    # Home
    if event.button == layout[6]:
        print("Home")
    
    # L1 (Left Bumper)
    if event.button == layout[7]:
        print("L1")

    # R1 (Right Bumper)
    if event.button == layout[8]:
        print("R1")

    # L3 (Left Stick)
    if event.button == layout[9]:
        print("L3")

    # R3 (Right Stick)
    if event.button == layout[10]:
        print("R3")
        

# Handle gamepad onButtonUp events
def onButtonUp(event):

    # Grab gamepad layout from dictionary
    layout = gamepadDict[event.instance_id][1]

    # North
    if event.button == layout[0]:
        ...

    # West
    if event.button == layout[1]:
        ...

    # South
    if event.button == layout[2]:
        ...

    # East
    if event.button == layout[3]:
        ...
    
    # Share
    if event.button == layout[4]:
        ...

    # Options
    if event.button == layout[5]:
        ...

    # Home
    if event.button == layout[6]:
        ...
    
    # L1 (Left Bumper)
    if event.button == layout[7]:
        ...

    # R1 (Right Bumper)
    if event.button == layout[8]:
        ...

    # L3 (Left Stick)
    if event.button == layout[9]:
        ...

    # R3 (Right Stick)
    if event.button == layout[10]:
        ...


# main loop
def main():

    print("Input Capture Started")

    loop = True
    while loop:

        # Handle events
        for event in pygame.event.get():

            # Get Button DOWN gamepad events
            if event.type == pygame.JOYBUTTONDOWN:
                onButtonDown(event)

            # Get Button UP gamepad events
            if event.type == pygame.JOYBUTTONUP:
                onButtonUp(event)

            # Handle new gamepad connections
            if event.type == pygame.JOYDEVICEADDED:
                onGamepadConnected(event)

            # Handle gamepad disconnections
            if event.type == pygame.JOYDEVICEREMOVED:
                onGamepadRemoved(event)

            # Handle gamepad hat buttons
            if event.type == pygame.JOYHATMOTION:
                ...

        

# Run the program
if __name__ == "__main__":
    main()
    pygame.quit()