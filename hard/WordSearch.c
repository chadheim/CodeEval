#include <stdio.h>
#include <math.h>

char b[3][4] = {
    { 'A', 'B', 'C', 'E' },
    { 'S', 'F', 'C', 'S' },
    { 'A', 'D', 'E', 'E' }
};

int m[3][4] = {
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 0, 0 }
};

char w[16];

int search(int i, int r, int c) {
    int match = 0;
    m[r][c] = 1;
    if (w[i] != b[r][c])
        match = 0;
    else if (w[i + 1] == '\n' || w[i + 1] == '\0')
        match = 1;
    else if (r > 0 && b[r - 1][c] == w[i + 1] && !m[r - 1][c])
        match = search(i + 1, r - 1, c);
    else if (r < 2 && b[r + 1][c] == w[i + 1] && !m[r + 1][c])
        match = search(i + 1, r + 1, c);
    else if (c > 0 && b[r][c - 1] == w[i + 1] && !m[r][c - 1])
        match = search(i + 1, r, c - 1);
    else if (c < 3 && b[r][c + 1] == w[i + 1] && !m[r][c + 1])
        match = search(i + 1, r, c + 1);
    m[r][c] = 0;
    return match;
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    while (fgets(w, 16, f)) {
        int found = 0;
        for (int r = 0; r < 3 && !found; ++r)
            for (int c = 0; c < 4 && !found; ++c)
                found = search(0, r, c);
        if (found)
            printf("True\n");
        else
            printf("False\n");
    }
    fclose(f);
    return 0;
}