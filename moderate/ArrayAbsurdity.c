#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char l[1024];
    FILE *f = fopen(argv[1], "r");
    while (fgets(l, 1024, f)) {
        char *s = strchr(l, ';');
        *s = '\0';
        int n = atoi(l);
        int *m = calloc(n, sizeof(int));
        s = strtok(s + 1, ",");
        while (s) {
            n = atoi(s);
            if (!m[n])
                m[n] = 1;
            else
                break;
            s = strtok(NULL, ",");
        }
        printf("%d\n", n);
        free(m);
    }
    fclose(f);
    return 0;
}