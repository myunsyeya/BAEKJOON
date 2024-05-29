#include <stdio.h>

int basket[101];

int main()
{
    int N, M;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int s, e, k;
        scanf(" %d %d %d", &s, &e, &k);
        while (s <= e) basket[s++] = k;
    }
    for (int i = 1; i <= N; i++) printf("%d ", basket[i]);
    return 0;
}