#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

void dfs(vector<int> &can, vector<int> site[], int v)
{
    for (int w : site[v]) {
        if (!can[w]) { can[w]=1; dfs(can, site, w); }
    }
}

int main()
{
    fio();

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> can(N);
        vector<int> site[101];
        int K; cin >> K;
        for (int i = 0; i < K; i++) {
            int v, w; cin >> v >> w;
            site[v].push_back(w);
            site[w].push_back(v);
        }
        dfs(can, site, 0);
        bool answer = true;
        for (int i = 0; i < N; i++) {
            if (!can[i]) { answer = false; break; }
        }
        cout << ((answer) ? "Connected." : "Not connected.") << '\n';
    }

    return 0;
}