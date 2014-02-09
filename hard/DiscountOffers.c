#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>
#include <string.h>

#ifndef max
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#endif

struct list {
    char *data[64];
    int length;
};

struct list names;
struct list products;

struct cache_node {
    struct cache_node *next;
    int key;
    float value;
};

struct cache {
    struct cache_node **data;
    int size;
};

struct cache ss_cache;
struct cache ssmax_cache;

void cache_alloc(struct cache *c, int size) {
    c->size = size;
    c->data = calloc(size, sizeof(struct cache_node *));
}

void cache_free(struct cache *c) {
    for (int i = 0; i < c->size; ++i) {
        while (c->data[i]) {
            struct cache_node *n = c->data[i];
            c->data[i] = c->data[i]->next;
            free(n);
        }
    }
    free(c->data);
}

int cache_hash(struct cache *c, int key) {
    return key % c->size;
}

int cache_find(struct cache *c, int key, float *value) {
    struct cache_node *n = c->data[cache_hash(c, key)];
    while (n != NULL) {
        if (n->key == key) {
            *value = n->value;
            return 1; 
        }
        n = n->next;
    }
    return 0;
}

void cache_add(struct cache *c, int key, float value) {
    struct cache_node *n;
    n = malloc(sizeof(struct cache_node));
    n->key = key;
    n->value = value;
    int h = cache_hash(c, key);
    n->next = c->data[h];
    c->data[h] = n;
}

void list_parse(struct list *list, char *data) {
    list->length = 0;
    char *e = strtok(data, ",");
    while(e != NULL) {
        list->data[list->length] = e;
        ++list->length;
        e = strtok(NULL, ",");
    }
}

void upper(char *str) {
    while(*str) {
        *str = toupper(*str);
        ++str;
    }
}

int letters(char *str) {
    int cnt = 0;
    while(*str) {
        if(isalpha(*str))
            ++cnt;
        ++str;
    }
    return cnt;
}

int isvowel(int ch) {
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'Y');
}

int vowels(char *str) {
    int cnt = 0;
    while(*str) {
        if(isvowel(*str))
            ++cnt;
        ++str;
    }
    return cnt;
}

int consonants(char *str) {
    int cnt = 0;
    while(*str) {
        if(isalpha(*str) && !isvowel(*str))
            ++cnt;
        ++str;
    }
    return cnt;
}

float ss_calc(char* name, char* product) {
    float value = 0;
    int ln = letters(name);
    int lp = letters(product);
    if(lp % 2 == 0) {
        value = vowels(name) * 1.5f;
    } else {
        value = consonants(name);
    }
    int m = (ln <= lp) ? ln : lp;
    int n = 2;
    while (n <= m) {
        if(lp % n == 0 && ln % n == 0) {
            value *= 1.5f;
            break;
        }
        n+= 1;
    }
    return value;
}

float ss(int n, int p) {
    float v = 0.0f;
    int k = n * products.length + p;
    if (!cache_find(&ss_cache, k, &v)) {
        v = ss_calc(names.data[n], products.data[p]);
        cache_add(&ss_cache, k, v);
    }
    return v;
}

float ss_calc_max_n(int n, int markers) {
    float v = 0;
    if (n < names.length) {
        if (!cache_find(&ssmax_cache, markers, &v)) {
            for (int p = 0; p < products.length; ++p)
                if ((markers & (1 << p)) == 0)
                    v = max(v, ss(n, p) + ss_calc_max_n(n + 1, markers | (1 << p)));
            cache_add(&ssmax_cache, markers, v);
        }
    }
    return v;
}

float ss_calc_max_p(int p, int markers) {
    float v = 0;
    if (p < products.length) {
        if (!cache_find(&ssmax_cache, markers, &v)) {
            for (int n = 0; n < names.length; ++n)
                if ((markers & (1 << n)) == 0)
                    v = max(v, ss(n, p) + ss_calc_max_p(p + 1, markers | (1 << n)));
            cache_add(&ssmax_cache, markers, v);
        }
    }
    return v;
}

int main(int argc, char *argv[]) {
    char l[1024];
	FILE *f = fopen(argv[1], "r");
	while (fgets(l, 1024, f) != NULL) {
        if(*l != '\n') {
            upper(l);
            char *p = strchr(l, '\n');
            if (p) *p = '\0';
            p = strchr(l, ';');
            *p = '\0';

            list_parse(&names, l);
            list_parse(&products, p + 1);

            cache_alloc(&ss_cache, names.length * products.length);
            cache_alloc(&ssmax_cache, 1024);

            if (names.length > 0 && products.length > 0) {
                if (names.length <= products.length) {
                    printf("%0.2f\n", ss_calc_max_n(0, 0));
                } else {
                    printf("%0.2f\n", ss_calc_max_p(0, 0));
                }
            } else {
                printf("0.00\n");
            }

            cache_free(&ssmax_cache);
            cache_free(&ss_cache);
        }
    }
    fclose(f);
	return 0;
}
