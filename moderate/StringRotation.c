#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *str, char a, char b) {
    char *n = strchr(str, a);
    if (n)
        *n = b;
    return n;
}

void rotate(char *s2) {
    int len = strlen(s2);
    char c = s2[0];
    for (int i = 0; i < len - 1; ++i)
        s2[i] = s2[i + 1];
    s2[len - 1] = c;
}

int is_rotation(char *s1, char *s2) {
    int len = strlen(s1);
    for (int i = 0; i < len; ++i) {
        if (strcmp(s1, s2) == 0)
            return 1;
        rotate(s2);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    char line[1024];
    while (fgets(line, 1024, f)) {
        if (line[0] != '\n') {
            replace(line, '\n', '\0');

            if (is_rotation(line, replace(line, ',', '\0') + 1))
                printf("True\n");
            else
                printf("False\n");
        }
    }

    fclose(f);
    return 0;
}