#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define M (200 * 2)

int n, m, r, x, y, i, j, k, cnt;
int sz1[M + 1], sz2[M + 1], ss[M + 1];
int dp[M / 4 + 1][M / 4 + 1];
int parent[M], rank[M];

void initial_set(int i) {
    int *sz;
    parent[i] = i;
    rank[i] = 0;
    sz = (i <= m) ? sz1 : sz2;
    sz[i] = 1;
}

int find_set(int i) {
    int j = i;
    while (i != parent[i]) {
        i = parent[i];
    }
    while (j != i) {
        int k = parent[j];
        parent[j] = i;
        j = k;
    }
    return i;
}

void union_set(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if (x == y) {
        return;
    }
    if (rank[x] > rank[y]) {
        parent[y] = x;
        sz1[x] += sz1[y];
        sz2[x] += sz2[y];
    } else {
        if (rank[x] == rank[y]) {
            rank[y]++;
        }
        parent[x] = y;
        sz1[y] += sz1[x];
        sz2[y] += sz2[x];
    }
}

int main() {
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%d%d", &m, &r);
        for (i = 1; i <= 2 * m; ++i) {
            initial_set(i);
        }
        for (i = 0; i < r; i++) {
            scanf("%d%d", &x, &y);
            union_set(x, m + y);
        }
        for (i = 1; i <= 2 * m; ++i) {
            if (i == find_set(i)) {
                ss[cnt++] = i;
            }
        }
        dp[0][0] = 1;
        for (i = 0; i < cnt; ++i) {
            for (j = m / 2; j >= sz1[ss[i]]; --j) {
                for (k = m / 2; k >= sz2[ss[i]]; --k) {
                    dp[j][k] = dp[j - sz1[ss[i]]][k - sz2[ss[i]]];
                }
            }
        }
        for (i = m / 2; i >= 0; i--) {
            if (dp[i][i] == 1) {
                printf("%d\n", i);
                break;
            }
        }
        memset(sz1, 0, sizeof(sz1));
        memset(sz2, 0, sizeof(sz2));
        memset(ss, 0, sizeof(ss));
        memset(dp, 0, sizeof(dp));
    }
    return 0;
}
