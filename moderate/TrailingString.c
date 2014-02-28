#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *str, char a, char b) {
    char *n = strchr(str, a);
    if (n)
        *n = b;
    return n;
}

char *strstrr(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 < len2)
        return NULL;

    char *p1 = str1 + len1;
    char *p2 = str2 + len2;
    while (p2 > str2)
        if (*(--p1) != *(--p2))
            return NULL;
    return p1;
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    char line[1024];
    while (fgets(line, 1024, f)) {
        if (line[0] != '\n') {
            replace(line, '\n', '\0');

            printf("%d\n", strstrr(line, replace(line, ',', '\0') + 1) != NULL);
        }
    }

    fclose(f);
    return 0;
}