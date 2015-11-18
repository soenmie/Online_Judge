#include <stdio.h>
#include <stdlib.h>
#define N 100
#define max(a, b) ((a) > (b) ? (a) : (b))

int r, c, i, j, longest = 1;
int mat[N][N], stat[N][N], seq[N * N];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int cmp(const void *a, const void *b) {
    int aa = *(int *)a, bb = *(int *)b;
    return mat[bb / c][bb % c] - mat[aa / c][aa % c];
}

int main() {
    scanf("%d%d", &r, &c);
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            scanf("%d", &mat[i][j]);
            seq[i * c + j] = i * c + j;
        }
    }
    qsort(seq, r * c, sizeof(int), cmp);

    for (i = 0; i < r * c; ++i) {
        int x = seq[i] / c, y = seq[i] % c;
        stat[x][y] = 1;
        for (j = 0; j < 4; ++j) {
            int xx = x + dx[j], yy = y + dy[j];
            if (xx < 0 || xx >= r || yy < 0 || yy >= c ||
                    mat[xx][yy] <= mat[x][y]) {
                continue;
            }
            stat[x][y] = max(stat[x][y], stat[xx][yy] + 1);
        }
        longest = max(longest, stat[x][y]);
    }
    printf("%d\n", longest);
    return 0;
}
