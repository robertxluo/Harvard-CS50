from cs50 import get_int


def main():

    # Prompt user to enter a number between 0 and 23
    while True:
        height = get_int("Height: ")
        if height >= 0 and height <= 23:
            break

    spaces = height - 1
    blocks = 1

    # Print the rows
    for i in range(height):

        # Print the spaces
        for j in range(spaces):
            print(" ", end='')

        # Print the blocks
        for k in range(blocks):
            print("#", end='')

        spaces -= 1
        blocks += 1
        print("  ", end='')

        # Print the blocks
        for k in range(blocks - 1):
            print("#", end='')

        print()


if __name__ == "__main__":
    main()