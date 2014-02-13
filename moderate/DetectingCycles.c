#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int read_numbers(FILE *f, int *n, int max) {
    int c = 0;
    char line[1024];
    if(fgets(line, 1024, f)) {
        char *s = strtok(line, " ");
        while(s && c < max) {
            n[c] = atoi(s);
            ++c;
            s = strtok(NULL, " ");
        }
    }
    return c;
}

int main(int argc, char* argv[]) {
    int n[256], sz;
    FILE *f = fopen(argv[1], "r");
    while ((sz = read_numbers(f, n, 256)) > 0) {
        
        int g[100];
        memset(g, -1, 100 * sizeof(int));
        
        for(int i = 0; i < sz-1; ++i) {
            int c = n[i];
            if(g[c] < 0) {
                g[c] = n[i+1];
            } else {
                printf("%d", c);
                int p = g[c];
                while(g[c] != g[p]) {
                    printf(" %d", p);
                    p = g[p];
                }
                printf("\n");
                break;
            }
        }
    }
    fclose(f);
    return 0;
}