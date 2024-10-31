#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

typedef long long ll;

int main()
{
    fio();

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        int dum;
        for (int i = 0; i < 2*M; i++) cin >> dum;
        cout << (N-1) << '\n';
    }

    return 0;
}