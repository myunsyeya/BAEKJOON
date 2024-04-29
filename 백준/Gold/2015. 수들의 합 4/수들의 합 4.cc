#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

typedef long long ll;
ll A[202020], S[202020];    // local stack overflow

int main()
{
    fio();
    ll N, K;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];

    map<ll, ll> cnt;
    ll ans = 0;
    for (int i = 0; i <= N; i++) {
        // S[i] - S[j-1] = K
        // S[j-1] = S[i] - K;
        ans += cnt[S[i] - K];
        cnt[S[i]]++;
    }
    cout << ans;
    return 0;
}