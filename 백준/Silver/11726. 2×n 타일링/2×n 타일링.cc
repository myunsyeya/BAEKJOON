#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int memo[1001];

int dp(int x)
{
    if (memo[x]) return memo[x];
    memo[x] = dp(x-1) + dp(x-2);
    memo[x] %= 10007;
    return memo[x];
}

int main()
{
    fio();
    int n; cin >> n;
    memo[1] = 1;
    memo[2] = 2;

    cout << dp(n);
    return 0;
}