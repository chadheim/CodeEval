#include <stdio.h>
#include <stdlib.h>

int is_eol(int c) {
    return c == '\n' ||
           c == '\0';
}

int is_closer(int c) {
    return c == '}' || 
           c == ']' || 
           c == ')';
}

int is_pair(int a, int b) {
    return (a == '(' && b == ')') || 
           (a == '[' && b == ']') || 
           (a == '{' && b == '}');
}

char * match(char *chars) {
    if (is_eol(*chars) || is_closer(*chars))
        return chars;
    char *end = match(chars + 1);
    if (!is_pair(*chars, *end))
        return chars;
    return match(end + 1);
}

int main(int argc, char* argv[]) {
    char line[1024];
    FILE *f = fopen(argv[1], "r");
    while (fgets(line, 1024, f)) {
        if (line[0] != '\n') {
            char *m = match(line);
            if (is_eol(*m))
                printf("True\n");
            else
                printf("False\n");
        }
    }
    fclose(f);
    return 0;
}