#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct trie {
    struct trie *letter[ALPHABET_SIZE];
};

int skip_comma;
char word[1024];
int word_size;
char letters[1024];
int letters_size;

void insert_combinations(struct trie *node, int word_pos) {
    if (word_pos < word_size) {
        for (int i = 0; i < letters_size; ++i) {
            int c = letters[i] - 'a';
            if (!node->letter[c])
                node->letter[c] = calloc(1, sizeof(struct trie));
            insert_combinations(node->letter[c], word_pos + 1);
        }
    }
}

void print_combinations(struct trie *node, int word_pos) {
    int node_empty = 1;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->letter[i]) {
            node_empty = 0;
            word[word_pos] = i + 'a';
            print_combinations(node->letter[i], word_pos + 1);
        }
    }
    if (node_empty) {
        if (!skip_comma)
            printf(",");
        skip_comma = 0;

        word[word_pos] = '\0';
        printf("%s", word);
    }
}

void release(struct trie *node) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->letter[i]) {
            release(node->letter[i]);
            free(node->letter[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    FILE *f = fopen(argv[1], "r");

    while (fscanf(f, "%d,%s", &word_size, letters) == 2) {

        letters_size = strlen(letters);

        struct trie *root = calloc(1, sizeof(struct trie));

        insert_combinations(root, 0);

        skip_comma = 1;
        print_combinations(root, 0);

        printf("\n");

        release(root);
        free(root);
    }

    fclose(f);
    return 0;
}