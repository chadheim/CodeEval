#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_numbers(FILE *f, int *n, int max) {
    int c = 0;
    char line[1024];
    if(fgets(line, 1024, f)) {
        char *s = strtok(line, ",");
        while(s && c < max) {
            n[c] = atoi(s);
            ++c;
            s = strtok(NULL, ",");
        }
    }
    return c;
}

int sum_to_zero(int *n, int sz, int start, int c, int r, int sum) {
    int count = 0;
    if(r < c) {
        sum += n[start];
        for(int i=start; i<sz-c+r; ++i) {
            count += sum_to_zero(n, sz, i+1, c, r+1, sum);
        }
    } else {
        return (sum == 0);
    }
    return count;
}

int main(int argc, char* argv[]) {
    int n[256], sz;
    FILE *f = fopen(argv[1], "r");
    while ((sz = read_numbers(f, n, 256)) > 0) {
        printf("%d\n", sum_to_zero(n, sz, 0, 4, 0, 0));
    }
    fclose(f);
    return 0;
}