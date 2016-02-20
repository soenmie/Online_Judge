#include <stdio.h>
#include <stdlib.h>

#define N 100000

#define max(a, b) ((a) > (b) ? (a) :(b))

int dp[N + 1], n, m, i, j, c, v;

int main() {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; ++i) {
        scanf("%d%d", &c, &v);
        for (j = m; j >= c; --j) {
            dp[j] = max(dp[j], dp[j - c] + v);
        }
    }
    printf("%d\n", dp[m]);
    return 0;
}
