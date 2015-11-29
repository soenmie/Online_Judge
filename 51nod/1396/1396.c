#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000000

char s[N + 1];
int n, i, A[N + 1], B[N + 1], sum;

int main () {
    gets(s);
    n = strlen(s);
    A[i] = sum = 0;
    for (i = 0; i < n; ++i) {
        sum += s[i] == '0';
        A[i + 1] = sum;
    }
    B[n] = sum = 0;
    for (i = n - 1; i >= 0; --i) {
        sum += s[i] == '1';
        B[i] = sum;
    }
    for (i = 0; i <= n; ++i) {
        if (A[i] == B[i]) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
