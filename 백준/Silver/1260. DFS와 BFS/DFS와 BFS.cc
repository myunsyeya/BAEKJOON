#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define fio() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false);

const int MAX=1010;

int N, M, V;
int visited[MAX], VIS[MAX];
vector<int> graph[MAX];

void dfs_list(int cur) {
    visited[cur] = true;
    cout << cur << ' ';
    for (int next : graph[cur]) {
        if (!visited[next]) dfs_list(next);
    }
}

void bfs() {
    queue<int> Q;
    VIS[V] = true;
    Q.push(V);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for (int next : graph[cur]) {
            if (!VIS[next]) { VIS[next] = true; Q.push(next); }
        }
    }
}

int main()
{
    fio();
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i <= N; i++) sort(graph[i].begin(), graph[i].end());
    dfs_list(V);
    cout << '\n';
    bfs();
    return 0;
}