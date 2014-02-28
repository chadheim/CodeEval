#include <stdio.h>
#include <stdlib.h>

int reverse(int n) {
    int r = 0;
    while (n) {
        r *= 10;
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");

    int n, r, i;
    while (fscanf(f, "%d ", &n) == 1) {

        i = 0;
        while (n != (r = reverse(n))) {
            n += r;
            ++i;
        }

        printf("%d %d\n", i, n);
    }

    fclose(f);
    return 0;
}