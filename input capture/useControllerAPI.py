import pygameTest

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



# Run the program
if __name__ == "__main__":
    pygameTest.init()
    buttonCallBacks = [north, west, south, east, share, options, home, l1, r1, l3, r3]
    pygameTest.getButtonDownCallback(buttonCallBacks)
    print("exited")
