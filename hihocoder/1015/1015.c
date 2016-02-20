#include <stdio.h>
#include <memory.h>

#define P 10000
#define S 1000000

char pat[P + 1], str[S + 1];
int n, i, j, k, cnt, fail[P];
int main () {
    scanf("%d", &n);
    while (n-- > 0) {
        scanf("%s", pat);
        scanf("%s", str);
        memset(fail, -1, sizeof(fail));
        for (i = 1; pat[i]; ++i) {
            for (k = fail[i - 1]; k != -1 && pat[k + 1] != pat[i]; k = fail[k]);
            if (pat[k + 1] == pat[i]) {
                fail[i] = k + 1;
            }
        }
        i = j = cnt = 0;
        while (str[i]) {
            if (str[i] == pat[j]) {
                ++i;
                ++j;
            } else if (j == 0) {
                ++i;
            } else if (!pat[j]) {
                ++cnt;
                j = fail[j - 1] + 1;
            } else {
                j = fail[j - 1] + 1;
            }
        }
        if (!pat[j]) {
            ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
