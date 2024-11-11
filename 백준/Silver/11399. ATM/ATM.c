#include <stdio.h>
#include <stdlib.h>

int greater(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int main()
{
    int N;
    int answer = 0;
    int P[1010] = { 0 };
    scanf(" %d", &N);
    for (int i = 0; i < N;i++) scanf(" %d", P+i);
    
    qsort(P, N, sizeof(int), greater);

    for (int i = 1; i < N; i++) P[i] += P[i-1];
    for (int i = 0; i < N; i++) answer += P[i];
    printf("%d", answer);
    
    return 0;
}