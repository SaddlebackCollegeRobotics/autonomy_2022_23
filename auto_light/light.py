from enum import Enum


class Color(Enum):
    RED = 0
    GREEN = 1
    BLUE = 2


def write_color(color: str) -> None:
    print(f'Writing {color} to pi')

    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.write(str.encode('utf-8'))


def main():
    valid = False
    color = Color.RED

    while not valid:
        print('[INFO] Enter a color:')
        for x in Color:
            print(f'[{x.value}] {x.name}')
        
        try:
            color = Color(int(input('> ')))
            valid = True
        except:
            print('Invalid input\n')

    write_color(color.name)


if __name__ == '__main__':
    main()