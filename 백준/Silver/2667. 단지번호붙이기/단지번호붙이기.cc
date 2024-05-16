#include <stdio.h>
#include <stdlib.h>

int compare(int* a, int* b) {
    return (*a == *b) ? 0 : (*a > * b) ? 1 : -1;
}

int dfs(int (*_a)[27], int (*_v)[27], int _y, int _x) {
    int deltaX[4] = { 1, 0, -1, 0 };
    int deltaY[4] = { 0, 1, 0, -1 };
    int cnt = 1;

    _v[_y][_x] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = _x + deltaX[i];
        int ny = _y + deltaY[i];
        if (_a[ny][nx] && !_v[ny][nx])
            cnt += dfs(_a, _v, ny, nx);
    }

    return cnt;
}

int main() {
    int count = 0;
    int HN[128] = { 0, };
    int a[27][27] = { 0, };
    int v[27][27] = { 0, };
    int N = 0;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (a[i][j] && !v[i][j])
                HN[count++] = dfs(a, v, i, j);

    qsort(HN, count, sizeof(int), (int(*)(const void*, const void*))compare);

    printf("%d\n", count);
    for (int i = 0; i < count; i++) printf("%d\n", HN[i]);
}