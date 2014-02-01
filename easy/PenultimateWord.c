#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char l[1024], *w[2], *c;
    FILE *f = fopen(argv[1], "r");
    while (fgets(l, 1024, f)) {
		c = strtok(l, " ");
		while (c != NULL) {
			w[0] = w[1];
			w[1] = c;
			c = strtok(NULL, " ");
		}
		puts(w[0]);
    }
    return 0;
}