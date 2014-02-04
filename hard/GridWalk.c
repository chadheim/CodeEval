#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct node {
    struct node *list_next;
    struct node *hash_next;
    int x;
    int y;
};

struct node *head = NULL;
struct node *tail = NULL;
int list_length = 0;

struct node *map[1024];

int hash(int x, int y) {
    int h = (x >= 0) ? x : -x;
    h += (y >= 0) ? y : -y;
    h %= 1024;
    return h;
}

void map_add(struct node *n) {
    int h = hash(n->x, n->y);
    n->hash_next = map[h];
    map[h] = n;
}

int map_exists(int x, int y) {
    int h = hash(x, y);
    struct node *p = map[h];
    while (p) {
        if (p->x == x && p->y == y) {
            return 1;
        }
        p = p->hash_next;
    }
    return 0;
}

void list_add(int x, int y) {
    if (map_exists(x, y))
        return;

    struct node *n = malloc(sizeof(struct node));
    n->x = x;
    n->y = y;
    n->list_next = NULL;
    n->hash_next = NULL;
    if (!head)
        head = n;
    if (tail)
        tail->list_next = n;
    tail = n;
    ++list_length;

    map_add(n);
}

int sum_digits(int num) {
    if (num < 0)
        num = -num;
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int expand(int x, int y) {
    if (sum_digits(x + 1) + sum_digits(y) <= 19)
        list_add(x + 1, y);
    if (sum_digits(x - 1) + sum_digits(y) <= 19)
        list_add(x - 1, y);
    if (sum_digits(x) + sum_digits(y + 1) <= 19)
        list_add(x, y + 1);
    if (sum_digits(x) + sum_digits(y - 1) <= 19)
        list_add(x, y - 1);
}

int main(int argc, char* argv[]) {
    memset(map, 0, 1024 * sizeof(struct node *));
    list_add(0, 0);
    struct node *current = head;
    while (current) {
        expand(current->x, current->y);
        current = current->list_next;
    }
    printf("%d\n", list_length);
    return 0;
}