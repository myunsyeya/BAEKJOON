#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();
    int N, K; cin >> N >> K;
    int coin[11], cnt = 0;
    for (int i = N; i > 0; i--) cin >> coin[i];
    for (int i = 1; i <= N; i++) {
        if (!coin[i]) break;
        cnt += K / coin[i]; 
        K %= coin[i];
    }
    cout << cnt;

    return 0;
}