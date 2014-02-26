#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int x;
    int y;
};

double distance(struct point p0, struct point p1) {
    return sqrt((p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y));
}

int place(double buckets[2], double value) {
    for (int i = 0; i < 2; ++i) {
        if (buckets[i] < 0) {
            buckets[i] = value;
            return 1;
        } else if(buckets[i] == value) {
            return 1;
        }
    }
    return 0;
}

int is_square(struct point pts[4]) {
    double b[2] = { -1, -1 };

    for (int m = 0; m < 4; ++m)
        for (int n = m + 1; n < 4; ++n)
            if (!place(b, distance(pts[m], pts[n])))
                return 0;

    if (b[0] < 0 || b[1] < 0)
        return 0;

    return 1;
}

int main(int argc, char* argv[]) {
    struct point pts[4];
    FILE *f = fopen(argv[1], "r");
    while (fscanf(f, " (%d,%d), (%d,%d), (%d,%d), (%d,%d)", &pts[0].x, &pts[0].y, &pts[1].x, &pts[1].y, &pts[2].x, &pts[2].y, &pts[3].x, &pts[3].y) == 8) {
        if (is_square(pts))
            printf("true\n");
        else
            printf("false\n");
    }
    fclose(f);
    return 0;
}