#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int n;
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &n) == 1) {

        int c = 0;
        while (n) {
            if (n & 1)
                ++c;
            n >>= 1;
        }
        printf("%d\n", c);
    }
    fclose(f);
    return 0;
}