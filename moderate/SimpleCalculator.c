#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f;

void ws() {
    int c = getc(f);
    while (c == ' ')
        c = getc(f);
    ungetc(c, f);
}

void expect(int c) {
    ws();
    return (c == getc(f));
}

float eval() {
    ws();

    int c = getc(f);
    if (c == EOF || c == '\n')
        return 0;

    if (c == '(') {
        float v = expr();
        expect(')');
        return v;
    }

    if (c == '-') {
        return -expr();
    }



    //^
    //*
    ///
    //+
    //-
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    while (!feof(f)) {
        printf("%f\n", eval());
    }

    fclose(f);
    return 0;
}