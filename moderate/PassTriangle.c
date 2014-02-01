#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#ifndef max
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#endif

int *tree_data = NULL;
int *tree_sums = NULL;
int tree_length = 0;

int max_sum(int y, int x) {
	int i = (y * (y + 1) / 2) + x;
	if (i >= tree_length)
		return 0;
	if (tree_sums[i] < 0)
		tree_sums[i] = tree_data[i] + max(max_sum(y + 1, x), max_sum(y + 1, x + 1));
	return tree_sums[i];
}

int main(int argc, char* argv[]) {
	int n, sz = 0;
	FILE *f = fopen(argv[1], "r");
	while (fscanf(f, "%d", &n) == 1) {
		if (tree_length >= sz) {
			sz += 1024;
			tree_data = realloc(tree_data, sz * sizeof(int));
		}
		tree_data[tree_length] = n;
		tree_length++;
	}
	tree_sums = malloc(tree_length * sizeof(int));
	memset(tree_sums, -1, tree_length * sizeof(int));
	printf("%d", max_sum(0, 0));
	free(tree_data);
	free(tree_sums);
	return 0;
}