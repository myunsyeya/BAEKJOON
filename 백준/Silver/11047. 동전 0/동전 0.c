#include <stdio.h>

int main()
{
    int N, K;
    int answer = 0;
    int coin[11];
    scanf(" %d %d", &N, &K);
    
    for (int i = N; i > 0; i--) scanf(" %d", coin+i);
    for (int i = 1; i <= N; i++) {
        answer += K/coin[i];
        K %=coin[i];
    }
    
    printf("%d", answer);
    
    return 0;
}