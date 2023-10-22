# TODO
from cs50 import get_float

def get_cents():
    # TODO
    cents = get_float("Change owed: ")
    while cents < 0:
        cents = get_float("Change owed: ")
    return cents

def calculate_coins(cents, coin_value):
    coins = 0
    while cents >= coin_value:
        cents -= coin_value
        coins += 1
    return coins

# Ask how many cents the customer is owed
cents = get_cents()

#convert dollar ro cents
cents = int(cents * 100)

# Calculate the number of quarters to give the customer
quarters = calculate_coins(cents, 25)
cents -= quarters * 25

# Calculate the number of dimes to give the customer
dimes = calculate_coins(cents, 10)
cents -= dimes * 10

# Calculate the number of nickels to give the customer
nickels = calculate_coins(cents, 5)
cents -= nickels * 5

# Calculate the number of pennies to give the customer
pennies = calculate_coins(cents, 1)

# Sum coins
coins = quarters + dimes + nickels + pennies

# Print total number of coins to give the customer
print(coins)
