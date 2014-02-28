#include <stdio.h>

int main(int argc, char* argv[]) {
    short i = 1;
    char *p = &i;
    if (*p)
        printf("LittleEndian");
    else
        printf("BigEndian");
    return 0;
}