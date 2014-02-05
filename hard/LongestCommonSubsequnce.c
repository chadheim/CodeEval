#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <math.h>

#ifndef max
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#endif

int s[512][512];
char seq[512];
char *m, *n;
int o;

void btrack(int r, int c) {
    if (r != 0 && c != 0) {
        if (m[r - 1] == n[c - 1]) {
            seq[--o] = m[r - 1];
            btrack(r - 1, c - 1);
        } else if (s[r - 1][c] > s[r][c - 1]) {
            btrack(r - 1, c);
        } else {
            btrack(r, c - 1);
        }
    }
}

void lcs() {
    int ms = strlen(m);
    int ns = strlen(n);

    for (int i = 0; i < (ms + 1); ++i)
        s[i][0] = 0;
    for (int i = 0; i < (ns + 1); ++i)
        s[0][i] = 0;

    for (int r = 1; r < (ms + 1); ++r)
        for (int c = 1; c < (ns + 1); ++c)
            if (m[r - 1] == n[c - 1])
                s[r][c] = s[r - 1][c - 1] + 1;
            else
                s[r][c] = max(s[r][c - 1], s[r - 1][c]);

    o = s[ms][ns];
    seq[o] = '\0';

    btrack(ms, ns);
}

int main(int argc, char* argv[]) {
    char l[1024];
    FILE *f = fopen(argv[1], "r");
    while (fgets(l, 1024, f)) {
        if (*l != '\n') {
            char *p = strchr(l, '\n');
            if (p) *p = '\0';

            p = strchr(l, ';');
            *p = '\0';
            ++p;

            m = l;
            n = p;
            lcs();

            puts(seq);
        }
    }
    return 0;
}