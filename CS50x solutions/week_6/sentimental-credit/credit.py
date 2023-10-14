# TODO
from cs50 import get_string

def digit_sum(stored):
    sum = 0
    while stored > 0:
        remainder = stored % 10
        sum = sum + remainder
        stored = stored // 10
    return sum


def number_stock(num, number_2):
    loops = len(num) // 2
    numbers_storage = [0] * loops

    for i in range(loops):
        numbers_storage[i] = number_2 % 10
        number_2 = number_2 // 100

    return sum(numbers_storage)


def string_checker(num):
    return num.isdigit()


def main():
    num = ""
    while not string_checker(num):
        num = get_string("Number: ")

    # Convert input to an integer to simplify the work
    number_1 = int(num)
    number_2 = number_1

    # Calculate the sum for list_1
    loops = len(num) // 2
    numbers_storage_1 = [0] * loops
    sum_1 = 0

    for i in range(loops + 1):
        result = (number_1 % 10) * 2
        if i == 0:
            number_1 = number_1 // 10
        else:
            if result >= 10:
                numbers_storage_1[i - 1] = digit_sum(result)
                sum_1 += numbers_storage_1[i - 1]
                number_1 = number_1 // 100
            else:
                numbers_storage_1[i - 1] = result
                sum_1 += numbers_storage_1[i - 1]
                number_1 = number_1 // 100

    sum_2 = number_stock(num, number_2)
    total_sum = sum_1 + sum_2

    # Check if the card is valid or not
    if total_sum % 10 == 0:
        if len(num) == 15 and (num[0] == '3' and (num[1] == '4' or num[1] == '7')):
            print("AMEX")
        elif len(num) == 16 and num[0] == '5':
            print("MASTERCARD")
        else:
            print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()