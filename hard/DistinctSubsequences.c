#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_subseq(char *seq, char *subseq) {
    int count = 0;
    if(*subseq == '\0')
        return 1;
    while(*seq != '\0') {
        if(*seq == *subseq) {
            count += count_subseq(seq + 1, subseq + 1);
        }
        ++seq;
    }
    return count;
}

int main(int argc, char *argv[]) {
    char l[1024];
	FILE *f = fopen(argv[1], "r");
	while (fgets(l, 1024, f) != NULL) {
        if(*l != '\n') {
            char *p = strchr(l, '\n');
            if(p) *p = '\0';
            p = strchr(l, ',');
            *p = '\0';
            printf("%d\n", count_subseq(l, p+1));
        }
    }
    fclose(f);
	return 0;
}
