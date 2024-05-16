#include <iostream>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int memo[20];

int main()
{
    fio();
    int T; cin >> T;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for (int i = 4; i <= 11; i++) {
        memo[i] = memo[i-1] + memo[i-2] + memo[i-3];
    }
    while (T--) {
        int n; cin >> n;
        cout << memo[n] << '\n';
    }

    return 0;
}