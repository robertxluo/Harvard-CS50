from cs50 import get_float


def main():

    # Prompt user for an amount of change
    while True:
        change = get_float("Change owed: ")
        if change > 0:
            break

    coin = 0

    # Convert dollar to cents
    amount = round(change * 100)

    if amount % 25 != amount:
        coin += amount // 25
        amount = amount % 25

    # Check how many dimes fit in change
    if amount % 10 != amount:
        coin += amount // 10
        amount = amount % 10

    # Check how many nickels fit in change
    if amount % 5 != amount:
        coin += amount // 5
        amount = amount % 5

    # Check how many pennies fit in change
    if amount % 1 != amount:
        coin += amount // 1
        amount = amount % 1

    print(coin)


if __name__ == "__main__":
    main()