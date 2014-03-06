#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *gt;
    struct node *lt;
    float value;
};

void insert(struct node **h, float v) {
    if (*h == NULL) {
        (*h) = calloc(1, sizeof(struct node));
        (*h)->value = v;
    } else {
        if (v >= (*h)->value)
            insert(&((*h)->gt), v);
        else
            insert(&((*h)->lt), v);
    }
}

void print(struct node *h) {
    if (h != NULL) {
        print(h->lt);
        printf("%0.3f ", h->value);
        print(h->gt);
    }
}

void release(struct node **h) {
    if (*h != NULL) {
        release(&((*h)->gt));
        release(&((*h)->lt));
        free(*h);
        *h = NULL;
    }
}

int read_num(FILE *f, float *n) {
    int c = getc(f);
    if (c == EOF || c == '\n')
        return 0;
    ungetc(c, f);
    return fscanf(f, "%f", n);
}

int main(int argc, char *argv[]) {
    FILE *f = fopen(argv[1], "r");
    while (!feof(f)) {
        struct node *h = NULL;
        float n;
        while(read_num(f, &n))
            insert(&h, n);
        print(h);
        printf("\n");
        release(&h);
    }
    fclose(f);
    return 0;
}