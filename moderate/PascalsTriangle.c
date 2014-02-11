#include <stdio.h>
#include <math.h>

void row(int n) {
    if(n > 1) {
        row(n - 1);
        
        for(int i=0, j=1; i<n; ++i, j=(j*(n-i))/i)
            printf(" %d", j);
        
    } else {
        printf("1");
    }
}

int main(int argc, char* argv[]) {
    int n;
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d", &n) == 1) {
        row(n);
        printf("\n");
    }
    fclose(f);
    return 0;
}