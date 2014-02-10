#include <stdio.h>
#include <stdlib.h>

char code[] = {
    ' ',
    'E', 'T',
    'I', 'A', 'N', 'M',
    'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O',
    'H', 'V', 'F', '?', 'L', '?', 'P', 'J', 'B', 'X', 'C', 'Y', 'Z', 'Q', '?', '?',
    '5', '4', '?', '3', '?', '?', '?', '2', '?', '?', '+', '?', '?', '?', '?', '1', '6', '=', '/', '?', '?', '?', '?', '?', '7', '?', '?', '?', '8', '?', '9', '0'
};

int main(int argc, char *argv[]) {
    int c, p = 0;
    FILE *f = fopen(argv[1], "r");
    do {
        c = fgetc(f);
        switch(c) {
            case EOF:
            case '\n':
                printf("%c\n", code[p]);
                p = 0;
                break;
            case ' ':
                printf("%c", code[p]);
                p = 0;
                break;
            case '.':
                p = 2 * p + 1;
                break;
            case '-':
                p = 2 * p + 2;
                break;
        }
    } while(c != EOF);
    fclose(f);
    return 0;
}