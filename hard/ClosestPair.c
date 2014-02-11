#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point {
    int x, y;
};

int main(int argc, char *argv[]) {
    int n;
	FILE *f = fopen(argv[1], "r");
	while (fscanf(f, "%d\n", &n) == 1) {
        if(n > 0) {
            double min_dist = 10000;
            struct point *pts = malloc(n * sizeof(struct point));
            for(int i=0; i<n; ++i) {
                fscanf(f, "%d %d\n", &(pts[i].x), &(pts[i].y));
                for(int j=0; j<i; ++j) {
                    double dx = pts[i].x - pts[j].x;
                    double dy = pts[i].y - pts[j].y;
                    double d = sqrt((dx*dx)+(dy*dy));
                    if(d < min_dist)
                        min_dist = d;
                }
            }
            free(pts);
            if(min_dist < 10000)
                printf("%0.4f\n", min_dist);
            else
                printf("INFINITY\n");
        }
    }
    fclose(f);
	return 0;
}
