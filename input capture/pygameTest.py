import os

# Hide pygame welcome message
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"

import pygame
import fileinput
import threading

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


# Handle gamepad button events
def onButtonEvent(event, callbackArray):

    # Grab gamepad layout from dictionary
    layout = gamepadDict[event.instance_id][1]

    # Call function corresponding to button pressed
    for i in range(len(layout)):
        if (event.button == layout[i]):
            callbackArray[i]()
            break


# Calls functions corresponding to button DOWN events
def getButtonDownCallback(callbackArray):

    def async_wrapper():
        
        loop = True
        while loop:
            
            for event in pygame.event.get():
                # Get button DOWN gamepad events
                if event.type == pygame.JOYBUTTONDOWN:
                    onButtonEvent(event, callbackArray)

    t1 = threading.Thread(target=async_wrapper)
    t1.run()
    

# Calls functions corresponding to button UP events
def getButtonUpCallback(callbackArray):

    loop = True
    while loop:

        for event in pygame.event.get():

            # Get button UP gamepad events
            if event.type == pygame.JOYBUTTONDOWN:
                onButtonEvent(event, callbackArray)


# Main event loop
def init():

    def async_wrapper():
        loop = True
        while loop:

            # Handle events
            for event in pygame.event.get():

                # Get Button DOWN gamepad events
                if event.type == pygame.JOYBUTTONDOWN:
                    ...

                # Get Button UP gamepad events
                if event.type == pygame.JOYBUTTONUP:
                    ...

                # Handle new gamepad connections
                if event.type == pygame.JOYDEVICEADDED:
                    onGamepadConnected(event)

                # Handle gamepad disconnections
                if event.type == pygame.JOYDEVICEREMOVED:
                    onGamepadRemoved(event)

                # Handle gamepad hat buttons
                if event.type == pygame.JOYHATMOTION:
                    ...

        pygame.quit()

    t1 = threading.Thread(target=async_wrapper)
    t1.run()


# # main loop
# def main():
#     print("Input Capture Started")
#     startEventLoop()


# # Run the program
# if __name__ == "__main__":
#     main()
#     pygame.quit()