#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

const int MAX = 100010;

int N;
int parent[MAX];
vector<int> Tree[MAX];

void bfs()
{
    queue<int> q;
    parent[1] = 1;
    q.push(1);

    do {
        int cur = q.front(); q.pop();
        
        for (int next : Tree[cur]) {
            if (!parent[next]) {
                parent[next] = cur;
                q.push(next);
            }
        }
    } while(!q.empty());
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        Tree[u].push_back(v);
        Tree[v].push_back(u);
    }
    bfs();
    for (int i = 2; i <= N; i++)
        cout << parent[i] << '\n';
    return 0;
}