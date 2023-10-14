# TODO
from cs50 import get_int
height_list = [1, 2, 3, 4, 5, 6, 7, 8]

while 1:
    height = get_int("Height: ")
    if height in height_list:
        break
for row in range(height):
    for collum in range(height + 10):
        if collum == height or collum == height + 1:
            print(" ", end = '')
        elif collum < height:
            if collum + row >= height - 1:
                print("#", end = '')
            else:
                print(" ", end = '')
        elif collum > height:
            if collum - row < height + 3:
                print("#", end = '')
    print()