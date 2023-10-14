from pyfiglet import Figlet
import sys
import random

figlet = Figlet()

font_list = figlet.getFonts()

if len(sys.argv) < 2:
    text = input("Input: ")
    random_font = random.choice(font_list)
    figlet.setFont(font=random_font)
    print(figlet.renderText(text))
    sys.exit(0)

elif len(sys.argv) >= 2:
    if sys.argv[1] != '-f' or sys.argv[2] not in font_list:
        print("Invalid usage")
        sys.exit(1)
    else:
        text = input("Input: ")
        figlet.setFont(font=sys.argv[2])
        print(figlet.renderText(text))
        sys.exit(0)
