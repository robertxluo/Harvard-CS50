from cs50 import get_string
from sys import argv


def main():
   # Check to see that only one argument is given after ./vigenere and 2nd argument is alphabetical
    if len(argv) == 2 and argv[1].isalpha():

        # Prompt user for a plaintext
        plaintext = get_string("plaintext: ")

        # Ciphertext string to append to after converting the plaintext
        ciphertext = ''

        key = argv[1]
        key_length = len(argv[1])
        count = 0

        # For each character in plaintext string, check if it is an alphabet while preserving case and shift by key
        for i in plaintext:
            if i.isalpha():
                if i.isupper():
                    if key[count % key_length].islower():
                        alphabet = ord(i) + (ord(key[count % key_length]) - ord('a')) % 26
                    else:
                        alphabet = ord(i) + (ord(key[count % key_length]) - ord('A')) % 26

                    # Wrap around alphabet if the key letter is greater than 'Z'
                    if alphabet > ord('Z'):
                        alphabet -= 26
                    ciphertext += chr(alphabet)
                else:
                    if key[count % key_length].isupper():
                        alphabet = ord(i) + (ord(key[count % key_length]) - ord('A')) % 26
                    else:
                        alphabet = ord(i) + (ord(key[count % key_length]) - ord('a')) % 26

                     # Wrap around alphabet if the key letter is greater than 'Z'
                    if alphabet > ord('z'):
                        alphabet -= 26
                    ciphertext += chr(alphabet)
                count += 1
            else:
                ciphertext += i

        print("ciphertext: " + ciphertext)
        return 0
    else:
        print("Usage ./vigenere k")
        exit(1)


if __name__ == "__main__":
    main()