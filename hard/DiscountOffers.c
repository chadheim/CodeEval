#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <ctype.h>

struct List {
    char *data[64];
    int length;
};

struct List names;
struct List products;
float *ss;
float ss_max;
int taken[1024];

void list_parse(struct List *list, char *data) {
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
    while (n < m) {
        if(lp % n == 0 && ln % n == 0) {
            value *= 1.5f;
            break;
        }
        n+= 1;
    }
    return value;
}

float ss_calc_max(int row, float score) {
    for(int i=0; i<names.length; ++i) {
        if(!taken[i]) {
            taken[i] = 1;
            ss_calc_max(row + 1, ss[i * names.length + j])
            taken[i] = 0;
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
            printf("%s\n", l);
            char *p = strchr(l, ';');
            *p = '\0';
            
            list_parse(&names, l);
            list_parse(&products, p + 1);

            float *ss = malloc(names.length * products.length * sizeof(float));
            for(int i=0; i<products.length; ++i)
                for(int j=0; j<names.length; ++j)
                    ss[i*names.length+j] = ss_calc(names.data[j], products.data[i]);

            ss_calc_max(0, 0);
            printf("%f\n", ss_max);
            free(ss);
        }
    }
    fclose(f);
	return 0;
}
