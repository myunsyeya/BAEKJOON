#include <iostream>

using namespace std;

#define fio() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0)

int memo[1000001];

int dp(int x)
{
    if (x == 1) return 0;
    if (memo[x]) return memo[x];
    int mod3, mod2; mod3 = mod2 = 1000001;
    if (x % 3 == 0) mod3 = dp(x/3) + 1;
    if (x % 2 == 0) mod2 = dp(x/2) + 1;
    memo[x] = min(mod3, min(mod2, dp(x-1) + 1));
    return memo[x];
}

int main()
{
    fio();
    int X;
    cin >> X;
    cout << dp(X) << '\n';
    return 0;
}