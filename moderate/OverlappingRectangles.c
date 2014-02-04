#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    int m[4], n[4];
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, "%d,%d,%d,%d,%d,%d,%d,%d", 
        &m[0], &m[1], &m[2], &m[3], 
        &n[0], &n[1], &n[2], &n[3]) == 8) {

        if (m[0] > n[2]) printf("False\n");
        else if (m[1] < n[3]) printf("False\n");
        else if (m[2] < n[0]) printf("False\n");
        else if (m[3] > n[1]) printf("False\n");
        else printf("True\n");
    }
    fclose(f);
    return 0;
}