#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comma = 0;

void rotate_right(char *s, int start, int end) {
    char c = s[start];
    for (int i = start; i < end; ++i)
        s[i] = s[i + 1];
    s[end] = c;
}

void rotate_left(char *s, int start, int end) {
    char c = s[end];
    for (int i = end; i > start; --i)
        s[i] = s[i - 1];
    s[start] = c;
}

void permutate(char *s, int start, int end) {
    if (start < end) {
        for (int i = start; i <= end; ++i) {
            rotate_left(s, start, i);
            permutate(s, start + 1, end);
            rotate_right(s, start, i);
        }
    } else {
        if (comma) printf(",");
        printf("%s", s);
        comma = 1;
    }
}

int compare(const void * a, const void * b) {
    return (*(char*)a - *(char*)b);
}

void replace(char *s, char from, char to) {
    while (*s) {
        if (*s == from)
            *s = to;
        ++s;
    }
}

int main(int argc, char *argv[]) {
    char l[1024];
    FILE *f = fopen(argv[1], "r");
    while (fgets(l, 1024, f)) {
        replace(l, '\n', '\0');

        comma = 0;
        int len = strlen(l);
        qsort(l, len, sizeof(char), compare);
        permutate(l, 0, len - 1);
        printf("\n");
    }
    fclose(f);
    return 0;
}