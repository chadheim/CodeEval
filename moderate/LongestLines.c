#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int len;
    char *line[1024];
};

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    int n;
    fscanf(f, "%d\n", &n);

    struct item *items = calloc(n, sizeof(struct item));

    char line[1024];
    while (fgets(line, 1024, f)) {
        int len = strlen(line);
        for (int i = 0; i < n; ++i) {
            if (len > items[i].len) {
                for (int j = n - 1; j > i; --j) {
                    items[j].len = items[j - 1].len;
                    strcpy(items[j].line, items[j - 1].line);
                }
                items[i].len = len;
                strcpy(items[i].line, line);
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%s\n", items[i].line);

    fclose(f);
    return 0;
}