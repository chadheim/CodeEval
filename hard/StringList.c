#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie {
    struct trie *n[26];
};

void combinations(char *s, int l, int d, int m, struct trie *n) {
    if (d < m) {
        for (int i = 0; i < l; ++i) {
            int c = s[i] - 'a';
            if (!n->n[c])
                n->n[c] = calloc(1, sizeof(struct trie));
            combinations(s, l, d + 1, m, n->n[c]);
        }
    }
}

int comma;

void print(struct trie *n, int d, char *s) {
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        if (n->n[i]) {
            cnt += 1;
            s[d] = i + 'a';
            print(n->n[i], d + 1, s);
        }
    }
    if (cnt == 0) {
        if (comma)
            printf(",");
        s[d] = NULL;
        printf("%s", s);
        comma = 1;
    }
}

void release(struct trie *n) {
    for (int i = 0; i < 26; ++i) {
        if (n->n[i]) {
            release(n->n[i]);
            free(n->n[i]);
        }
    }
}

int cmp(const void * a, const void * b) {
    return (*(char*)a - *(char*)b);
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    int n;
    char s[1024];
    while (fscanf(f, "%d,%s", &n, s) == 2) {

        int l = strlen(s);
        qsort(s, l, sizeof(char), cmp);

        struct Node *r = calloc(1, sizeof(struct trie));
        combinations(s, l, 0, n, r);

        comma = 0;
        print(r, 0, s);
        printf("\n");

        release(r);
        free(r);
    }

    fclose(f);
    return 0;
}