#include <stdio.h>
#include <math.h>

int cycle[] = { 1, 2, 0 };

int digit(int pos) {
    if (pos == 0) return 0;
    if (pos == 1) return 1;
    pos -= (int) powf(2, floorf(log2f(pos)));
    return cycle[digit(pos)];
}

int main(int argc, char* argv[]) {
    int n, p, o;
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &n) == 1) {
        printf("%d\n", digit(n));
    }
    fclose(f);
    return 0;
}