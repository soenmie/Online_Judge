#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct trie_s trie_t;

struct trie_s {
    char val;
    int cnt;
    trie_t *chd[256];
};

void trie(trie_t **tr, char val) {
    *tr = malloc(sizeof(trie_t));
    (*tr)->val = val;
    (*tr)->cnt = 0;
    memset((*tr)->chd, 0, sizeof((*tr)->chd));
}

int n, m, i, tot;
char c;
trie_t *root, *cur;

int main() {
    trie(&root, '^');
    scanf("%d\n", &n);
    for (i = 0; i < n; ++i) {
        cur = root;
        while ((c = getchar()) != '\n') {
            if (cur->chd[c] == NULL) {
                trie(&cur->chd[c], c);
            }
            cur = cur->chd[c];
            ++cur->cnt;
        }
    }
    scanf ("%d\n", &m);
    for (i = 0; i < m; ++i) {
        cur = root;
        tot = -1;
        while ((c = getchar()) != '\n') {
            if (tot == 0) {
                continue;
            }
            if (cur->chd[c] == NULL) {
                tot = 0;
            }
            cur = cur->chd[c];
        }
        tot = tot != 0 ? cur->cnt : 0;
        printf("%d\n", tot);
    }
    return 0;
}
