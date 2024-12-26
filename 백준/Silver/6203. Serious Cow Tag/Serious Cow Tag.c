#include <stdio.h>

typedef struct Coor {
    int x;
    int y;
    int inActive;
} COOR;

#define sqdist(cow1, cow2) ((cow1.x - cow2.x) * (cow1.x - cow2.x) + (cow1.y - cow2.y) * (cow1.y - cow2.y))

int main() {
    int N;
    COOR cows[1010];
    int activeCows;
    
    scanf("%d", &N);
    activeCows = N;
    
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &cows[i].x, &cows[i].y);
        cows[i].inActive = 0;
    }
    
    int current = 1;
    while (activeCows > 1) {
        if (!cows[current].inActive) {
            int nearest = -1;
            for (int j = 1; j <= N; j++) {
                if (j != current && !cows[j].inActive) {
                    if (nearest == -1 || sqdist(cows[current], cows[j]) < sqdist(cows[current], cows[nearest])) {
                        nearest = j;
                    }
                }
            }
            cows[nearest].inActive = 1;
            activeCows--;
        }
        current = current % N + 1;
    }
    
    for (int i = 1; i <= N; i++) {
        if (!cows[i].inActive) {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}