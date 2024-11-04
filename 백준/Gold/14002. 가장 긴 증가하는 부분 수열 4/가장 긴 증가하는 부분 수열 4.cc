#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();

    int N; cin >> N;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    vector<vector<int>> dp(1001);

    for (int a : A) {
        int max_idx = 0;
        for (int i = 0; i < a; i++) if (dp[i].size() > dp[max_idx].size()) max_idx = i;
        dp[a] = dp[max_idx];
        dp[a].push_back(a);
    }

    int max_idx = 0;
    for (int a : A) {
        if (dp[a].size() > dp[max_idx].size()) max_idx = a;
    }

    cout << dp[max_idx].size() << '\n';
    for (int x : dp[max_idx]) cout << x << ' ';

    return 0;
}