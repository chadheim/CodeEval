#include <stdio.h>
#include <stdlib.h>

int contains(int *m, int len, int val) {
    for(int i=0; i<len; ++i)
        if(m[i] == val)
            return 1;
    return 0;
}

int find_min(int *m, int len) {
    int num = 0;
    while(contains(m, len, num))
        ++num;
    return num;
}

int main(int argc, char *argv[]) {
    int n, k, a, b, c, r;
	FILE *f = fopen(argv[1], "r");
	while (fscanf(f, "%d,%d,%d,%d,%d,%d\n", &n, &k, &a, &b, &c, &r) == 6) {
        int *m = malloc(n * sizeof(int));
        
        m[0] = a;
        for(int i=1; i<k; ++i)
            m[i] = (b * m[i-1] + c) % r;

        for(int i=k; i<n; ++i)
            m[i] = find_min(m+i-k, k);
        
        printf("%d\n", m[n-1]);
        free(m);
    }
    fclose(f);
	return 0;
}
