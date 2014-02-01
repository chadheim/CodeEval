#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b, c, i;
	FILE *f = fopen(argv[1], "r");
	while (fscanf(f, "%d %d %d\n", &a, &b, &c) == 3) {
		for (i = 1; i <= c; ++i) {
			if (i > 1) 
				printf(" ");

			if (i % a != 0 && i % b != 0) 
				printf("%d", i);
			if (i % a == 0) 
				printf("F");
			if (i % b == 0) 
				printf("B");
		}
		printf("\n");
	}
	fclose(f);
	return 0;
}