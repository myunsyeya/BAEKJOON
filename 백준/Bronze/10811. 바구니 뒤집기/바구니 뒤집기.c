#include <stdio.h>

int basket[101];

int main()
{
    int N, M;
    scanf(" %d %d", &N, &M);
    for (int i = 1; i <= N; i++) basket[i] = i;
    while (M--) {
        int i, j;
        scanf(" %d %d", &i, &j);
        while (i <= j) {
            if (i != j) {
                basket[i] ^= basket[j];
                basket[j] ^= basket[i];
                basket[i++] ^= basket[j--];
            } else { i++; j--; }
        }
    }
    for (int i = 1; i <= N; i++) printf("%d ", basket[i]);
    return 0;
}