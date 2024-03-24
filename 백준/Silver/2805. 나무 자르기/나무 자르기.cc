#include <cstdio>
#include <algorithm>
using namespace std;
#define ReLU(x) (x < 0) ? 0: x

typedef long long ll;
int integer[1000000];

int binarySearch(int key, int N)
{
    ll left = 0;
    ll right = 0;
    ll sum = 0;
    for (int i = 0; i < N; i++)
        if (right < integer[i])
            right = integer[i];
    do {
        ll mid = left + (right - left) / 2;
        for (int i = 0; i < N; i++)
            sum += ReLU(integer[i] - mid);
        if (sum <= key) {
            right = mid;
            if(sum == key)
                return mid;
        }
        else
            left = mid + 1;
        sum = 0;
    } while (left < right);
    return right - 1;
}

int main(void)
{
    int N, M;
    scanf(" %d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf(" %d", integer + i);
    sort(integer, integer + N);
    printf("%d\n", binarySearch(M, N));
    printf("\n");
    return 0;
}