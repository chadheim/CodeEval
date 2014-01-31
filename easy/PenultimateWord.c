#include <stdio.h>

int main(int argc, char* argv[]) {
    char l[1024], *b[2], *c, w;
    FILE *f = fopen(argv[1], "r");
    while (fgets(l, 1024, f)) {
        if (*l != '\n') {
            w = 0;
            c = l-1;
            do {
                ++c;
                if(*c == 0x0A) {
                    puts(b[1 - w]);
                } else if(*c == 0x20) {
                    *c = 0x00;
                } else if(c == l || *(c-1) == 0x00) {
                    w = 1 - w;
                    b[w] = c;
                }
            } while(*c != 0x0A);
        }
    }
    return 0;
}