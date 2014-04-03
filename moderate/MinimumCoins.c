#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int n;
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &n) == 1) {

        int a = n / 5;
        n %= 5;
        int b = n / 3;
        n %= 3;

        printf("%d\n", a + b + n);
    }
    fclose(f);
    return 0;
}
