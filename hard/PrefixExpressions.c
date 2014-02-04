#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

FILE *f;

void ws() {
    char c;
    do {
        c = getc(f);
    } while(c == ' ');
    ungetc(c, f);
}

int is_blank() {
    char c = getc(f);
    if(c == EOF || c == '\n')
        return 1;
    ungetc(c, f);
    return 0;
}

float eval() {
    ws();
    char c = getc(f);
    if(c == EOF || c == '\n') {
        return 0;
    } else if(c == '*') {
        return eval() * eval();
    } else if(c == '+') {
        return eval() + eval();
    } else if(c == '/') {
        return eval() / eval();
    }
    return c - '0';
}

int main(int argc, char* argv[]) {
    f = fopen(argv[1], "r");
    while(!feof(f)) {
        if(!is_blank())
            printf("%.0f\n", eval());
    }
    fclose(f);
    return 0;
}