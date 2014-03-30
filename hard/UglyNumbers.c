#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split(int sum, char *digits, int len) {
    if (len == 0) {
        //is ugly?
        return 0;
    }
    else {
        int ugly = 0;
        for (int i = 1; i < len; ++i) {

            ugly += split(sum + x, digits + i, len - 1);
        }
        return ugly;
    }
}

int ugly_count(char* digits) {
    return 0;
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    char line[1024];
    while (fgets(line, 1024, f)) {
        printf("%d\n", ugly_count(strtok(line, "\n")));
    }

    fclose(f);
    return 0;
}