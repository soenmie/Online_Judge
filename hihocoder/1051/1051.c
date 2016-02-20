#include <stdio.h>
#define N 100
#define max(a, b) ((a) > (b) ? (a) : (b))

int t, n, m, i, cnt, A[N + 2];
int main() {
    scanf("%d", &t);
    while (t-- > 0) {
        scanf ("%d%d", &n, &m);
        for (i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
        }
        if (m >= n) {
            printf("100\n");
            continue;
        }
        A[0] = 0, A[n + 1] = 101, cnt = 0;
        for (i = 0; i <= n - m; i++) {
            cnt = max(cnt, A[i + m + 1] - A[i] - 1);
        }
        printf("%d\n", cnt);
    }
    return 0;
}
