#include <stdio.h>
#include <stdlib.h>

int read_num(FILE *f, int *n) {
    int c = fgetc(f);
    if (c == '\n' || c == EOF) 
        return 0;
    ungetc(c, f);
    fscanf(f, " %d", n);
    return 2;
}

struct stack {
    struct stack *next;
    int value;
};

void push(struct stack **s, int n) {
    struct stack *t = malloc(sizeof(struct stack));
    t->next = *s;
    t->value = n;
    *s = t;
}

int pop(struct stack **s, int *n) {
    if(*s == NULL)
        return 0;
    struct stack *t = *s;
    *n = (*s)->value;
    *s = (*s)->next;
    free(t);
    return 1;
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");
    while(!feof(f)) {
        struct stack *s = NULL;
        int n;

        while(read_num(f, &n))
            push(&s, n);
            
        while(pop(&s, &n)) {
            printf("%d ", n);
            pop(&s, &n);
        }
        printf("\n");
    }
    fclose(f);
    return 0;
}