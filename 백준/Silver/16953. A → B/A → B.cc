#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

typedef long long ll;

int main()
{
    fio();

    ll A, B; cin >> A >> B;
    queue<pair<ll, int>> q;
    q.push({A, 1});

    while (!q.empty()) {
        ll N;
        int cnt;
        tie(N, cnt) = q.front(); q.pop();

        if (N > (ll)1e9) continue;
        if (N == B) { cout << cnt; return 0; }
        q.push({N*2, cnt+1});
        q.push({N*10+1, cnt+1});
    }
    cout << -1;

    return 0;
}