#include <stdio.h>
#include <stdlib.h>
#define N 6000000

int i, j, l, r, n, sz;
long long x, y, res;
long long stk[N], arr[N + 1], sum[N + 1];

int main () {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
        sum[i + 1] = sum[i] + arr[i];
    }
    for (i = 0; i <= n; ++i) {
        x = (i < n) ? arr[i] : -1;
        while (sz > 0 && arr[stk[sz - 1]] > x) {
            long long v;
            y = arr[stk[--sz]];
            j = (sz > 0) ? stk[sz - 1] : -1;
            v = (sum[i] - sum[j + 1]) * y;
            if (res < v) {
                res = v;
                l = j + 1;
                r = i - 1;
            }
        }
        stk[sz++] = i;
    }
    printf("%lld\n%d %d\n", res, l + 1, r + 1);
    return 0;
}
