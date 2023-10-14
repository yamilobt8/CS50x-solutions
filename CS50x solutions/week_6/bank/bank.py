greeting = input("Greeting: ").capitalize()

if greeting[0] == "H":
    if greeting == "Hello":
        print("$0")
    elif greeting[0:5] == "Hello" and (greeting[5] == " " or greeting[5] == ","):
        print("$0")
    elif greeting[0] == "H" and greeting[1] != "e":
        print("$20")
else:
    print("$100")