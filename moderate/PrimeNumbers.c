#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");

    int n;
    while (fscanf(f, "%d ", &n) == 1) {

        int c = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime(i)) {
                if (c > 0) { printf(","); }
                printf("%d", i);
                ++c;
            }
        }
        printf("\n");

    }

    fclose(f);
    return 0;
}