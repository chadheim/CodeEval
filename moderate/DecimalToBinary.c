#include <stdio.h>
#include <math.h>

void to_binary(int n) {
    if(n > 0) {
        to_binary(n / 2);
        printf("%d", n % 2);
    }
}

int main(int argc, char* argv[]) {
    int n;
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &n) == 1) {
        if(n > 0)
            to_binary(n);
        else
            printf("0");
        printf("\n");
    }
    fclose(f);
    return 0;
}