import sys

morse = {
    '.-': 'A', '.---': 'J', '...': 'S', '.----': '1', '.-.-.-': '.', '---...': ':',
    '-...': 'B', '-.-': 'K', '-': 'T', '..---': '2', '--..--': ',', '-.-.-.': ';',
    '-.-.': 'C', '.-..': 'L', '..-': 'U', '...--': '3', '..--..': '?', '-...-': '=',
    '-..': 'D', '--': 'M', '...-': 'V', '....-': '4', '.----.': '\'', '.-.-.': '+',
    '.': 'E', '-.': 'N', '.--': 'W', '.....': '5', '-.-.--': '!', '-....-': '-',
    '..-.': 'F', '---': 'O', '-..-': 'X', '-....': '6', '-..-.': '/', '..--.-': '_',
    '--.': 'G', '.--.': 'P', '-.--': 'Y', '--...': '7', '-.--.': '(', '.-..-.': '\"',
    '....': 'H', '--.-': 'Q', '--..': 'Z', '---..': '8', '-.--.-': ')', '...-..-': '$',
    '..': 'I', '.-.': 'R', '-----': '0', '----.': '9', '.-...': '&', '.--.-.': '@',
    '': ' '
}

with open(sys.argv[1]) as f:
    for line in f:
        print ''.join(map(lambda c: morse[c], line.rstrip('\n').split(' ')))
