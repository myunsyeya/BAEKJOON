#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();

    int N; cin >> N;
    vector<int> S(N);
    for (int& s : S) cin >> s;
    vector<int> dp(N);

    /*
    * 마지막 계단 N 번째를 기준으로.
    * N, N-1, dp[N-3]
    * N, dp[N-2]로 Table filling
    * 맨 마지막 계단을 밟아야 하므로 dp[N-1]을 반환
    * 예외처리 성가시네..
    */
    
    dp[0] = S[0];
    if (N > 1) dp[1] = S[0]+S[1];
    if (N > 2) dp[2] = S[2] + max(S[0], S[1]);
    for (int i = 3; i < N; i++) {
        dp[i] = S[i] + max(S[i-1]+dp[i-3], dp[i-2]);
    }

    cout << dp[N-1];

    return 0;
}