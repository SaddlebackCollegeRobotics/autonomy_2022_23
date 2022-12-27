import gamepad_input
import time

def north():
    print("North")

def west():
    print("West")

def south():
    print("South")

def east():
    print("East")

def share():
    print("Share")

def options():
    print("Options")

def home():
    print("Home")

def l1():
    print("L1")

def r1():
    print("R1")

def l3():
    print("L3")

def r3():
    print("R3")

def northUp():
    print("North Up")

def westUp():
    print("West Up")

def southUp():
    print("South Up")

def eastUp():
    print("East Up")

def shareUp():
    print("Share Up")

def optionsUp():
    print("Options Up")

def homeUp():
    print("Home Up")

def l1Up():
    print("L1 Up")

def r1Up():
    print("R1 Up")

def l3Up():
    print("L3 Up")

def r3Up():
    print("R3 Up")

def hatNorth():
    print("Hat North")

def hatSouth():
    print("Hat South")

def hatWest():
    print("Hat West")

def hatEast():
    print("Hat East")

def hatCentered():
    print("Hat Centered")


# Run the program
if __name__ == "__main__":

    # Set button callbacks
    buttonDownEvents = [north, west, south, east, share, options, home, l1, r1, l3, r3]
    buttonUpEvents = [northUp, westUp, southUp, eastUp, shareUp, optionsUp, homeUp, l1Up, r1Up, l3Up, r3Up]

    # Note: You can set a callback to 'None' if you don't want to use it

    # Set hat callbacks
    hatEvents = [hatNorth, hatSouth, hatWest, hatEast, hatCentered]

    # Async loop to handle gamepad button events
    gamepad_input.getButtonCallbacks(buttonDownEvents, buttonUpEvents, hatEvents)

    # How to get gamepad object and read axis values
    deadzone = 0.2
    
    while True:
        time.sleep(0.5)
        

        # Get gamepad object
        gamepad = gamepad_input.getGamepad(0)

        if gamepad != None:

            # Get left stick axis values
            (ls_x, ls_y) = gamepad_input.getLeftStick(gamepad, deadzone)
            (rs_x, rs_y) = gamepad_input.getRightStick(gamepad, deadzone)

            # Get trigger axis values
            (l2, r2) = gamepad_input.getTriggers(gamepad, deadzone)

            # Print axis values
            if ls_x > 0:
                print("LS Right")
            elif ls_x < 0:
                print("LS Left")

            if ls_y > 0:
                print("LS Down")
            elif ls_y < 0:
                print("LS Up")

            if rs_x > 0:
                print("RS Right")
            elif rs_x < 0:
                print("RS Left")

            if rs_y > 0:
                print("RS Down")
            elif rs_y < 0:
                print("RS Up")

            if l2 > 0:
                print("L2")
            
            if r2 > 0:
                print("R2")

    # Safely quit program
    # gamepad_input.quit()