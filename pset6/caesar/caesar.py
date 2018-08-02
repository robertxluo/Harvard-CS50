from cs50 import get_string
from sys import argv


def main():
    # Check to see that only one argument is given after ./caesar
    if len(argv) != 2:
        print("Usage ./caesar k")
        exit(1)

    # Prompt user for a plaintext
    plaintext = get_string("plaintext: ")

    # Ciphertext string to append to after converting the plaintext
    ciphertext = ''

    # Convert string to integer of key e.g. "5" to 5
    key = int(argv[1])

    # For each character in plaintext string, check if it is an alphabet while preserving case and shift by key
    for i in plaintext:
        if i.isalpha():
            if i.isupper():
                alphabet = ord(i) + key % 26
                if alphabet > ord('Z'):
                    alphabet -= 26
                ciphertext += chr(alphabet)
            else:
                alphabet = ord(i) + key % 26
                if alphabet > ord('z'):
                    alphabet -= 26
                ciphertext += chr(alphabet)
        else:
            ciphertext += i

    print("ciphertext: " + ciphertext)
    return 0


if __name__ == "__main__":
    main()