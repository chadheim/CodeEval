#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <limits.h>

#ifndef min
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

int *data, *sums;
int size;

int min_path(int x, int y) {
    int i = y * size + x;

    if (x < size && y < size && sums[i] <= 0) {
        if (x < size - 1 && y < size - 1)
            sums[i] = data[i] + min(min_path(x + 1, y), min_path(x, y + 1));
        else if (x < size - 1)
            sums[i] = data[y * size + x] + min_path(x + 1, y);
        else if (y < size - 1)
            sums[i] = data[y * size + x] + min_path(x, y + 1);
        else
            sums[i] = data[i];
    }

    return sums[i];
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &size) == 1) {
        data = malloc(size * size * sizeof(int));
        sums = calloc(size * size, sizeof(int));

        int i = 0, n;
        while (i < size * size) {
            if (i % size == 0)
                fscanf(f, "%d", &n);
            else
                fscanf(f, ",%d", &n);

            data[i++] = n;
        }

        printf("%d\n", min_path(0, 0));
        free(data);
        free(sums);
    }
    fclose(f);
    return 0;
}