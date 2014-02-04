#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    int i, s;
    char l[1024], c[256];
    FILE *f = fopen(argv[1], "r");
    while (fgets(l, 1024, f)) {
        for(i=0; i<256; ++i)
            c[i] = 0;
        
        s = strlen(l);
        for(i=0; i<s; ++i) {
            c[l[i]] += 1;
        }
        
        for(i=0; i<s && c[l[i]] > 1; ++i);
        
        printf("%c\n", l[i]);
    }
    fclose(f);
    return 0;
}