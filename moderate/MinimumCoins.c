#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int n;
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &n) == 1) {

        int c = 0;
        c += n / 5;
        n %= 5;
        c += n / 3;
        n %= 3;
        c += n;

        printf("%d\n", c);
    }
    fclose(f);
    return 0;
}
