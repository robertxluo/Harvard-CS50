from cs50 import get_int


# Get the credit card number the user entered
def getCardNumber():
    # Prompt user to enter credit card number
    cc_number = get_int("Number: ")
    return cc_number


# Check credit card length to see if it is a valid number based on LENGTH
def getCardLength(cc_number):
    digits = len(str(cc_number))

    if digits != 13 and digits != 15 and digits != 16:
        print("INVALID")
        return 0
    return digits


# Get the sum of digits of every other number multiplied by 2
def everyOtherSum(cc_number, digits):
    every_other = []
    every_other_sum = 0
    for i in range(digits):
        every_other.append((cc_number // 10) % 10 * 2)
        cc_number //= 100

        # Extract the two digit number into one digit and sum them (e.g. 14 = 1 + 4)
        if every_other[i] > 9:
            every_other[i] = every_other[i] % 10 + every_other[i] // 10
        every_other_sum += every_other[i]
    return every_other_sum


# Get the sum of digits not multiplied by 2
def nonMultipliedSum(cc_number, digits):
    non_multiplied_sum = 0
    for i in range(digits):
        non_multiplied_sum += cc_number % 10
        cc_number //= 100
    return non_multiplied_sum


# Check checksum and company identifiers to see if credit card number is valid
def check(cc_number, checksum):
    cc_number = str(cc_number)
    if checksum % 10 != 0:
        print("INVALID")
    elif cc_number[0] == '3' and (cc_number[1] == '4' or cc_number[1] == '7') and len(cc_number) == 15:
        print("AMEX")
    elif cc_number[0] == '5' and (cc_number[1] >= '1' and cc_number[1] <= '5') and len(cc_number) == 16:
        print("MASTERCARD")
    elif cc_number[0] == '4' and (len(cc_number) == 13 or len(cc_number) == 16):
        print("VISA")
    else:
        print("INVALID")


def main():
    cc_number = getCardNumber()
    digits = getCardLength(cc_number)
    if digits == 0:
        return 0
    every_other_sum = everyOtherSum(cc_number, digits)
    non_multiplied_sum = nonMultipliedSum(cc_number, digits)
    checksum = every_other_sum + non_multiplied_sum
    check(cc_number, checksum)
    return 0


if __name__ == "__main__":
    main()