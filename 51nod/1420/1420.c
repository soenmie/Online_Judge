#include <stdio.h>
#include <stdlib.h>

#define N 500000

int i, j, m, n, A[N];

int cmp(const void *a ,const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
    }
    qsort(A, n, sizeof(int), cmp);
    for (i = n - 1, j = n / 2 - 1; i >= n / 2 && j >= 0; --i, --j) {
        if (A[i] == 0) {
            continue;
        }
        for (/* void */; A[j] * 2 > A[i] && j >= 0; --j);
        if (j >= 0) {
            A[j] = 0;
            ++m;
        }
    }
    printf("%d\n", n - m);
    return 0;
}
