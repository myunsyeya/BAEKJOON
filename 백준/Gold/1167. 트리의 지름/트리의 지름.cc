#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int newroot = 1;
int mxlen = 0;
vector<pair<int,int>> graph[100001];

// cycle이 없으니 부모 노드로 가는 방향만 차단하면 그만.
void dfs(int cur, int par, int wei) {
    for (auto nxt: graph[cur]) {
        if (nxt.first == par) continue;
        dfs(nxt.first, cur, wei + nxt.second);
    }
    if (wei > mxlen) {
        mxlen = wei;
        newroot = cur;
    }
    
}

int main()
{
    fio();

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        int v; cin >> v;
        while (v != -1) {
            int w; cin >> w;
            graph[a].push_back({v, w});
            cin >> v;
        }
    }

    dfs(1, -1, 0);
    mxlen = 0;
    dfs(newroot, -1, 0);
    
    cout << mxlen;
    return 0;
}