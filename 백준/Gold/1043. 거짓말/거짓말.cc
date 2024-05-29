#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

#define MAX_N ((int) 51)

int parent[MAX_N];
set<int> true_party;
vector<int> group;

void Make_set(int n)
{
    for (int i = 1; i <= n; i++) parent[i] = i;
}

int Find(int u)
{
    if (parent[u] == u) return u;
    return Find(parent[u]);
}

void Union(int u, int v)
{
    parent[Find(u)] = Find(v);
}

int main()
{
    fio();
    int N, M, K, answer;
    int knower[MAX_N];
    cin >> N >> M >> K;
    answer = M;
    Make_set(N);
    for (int i = 0; i < K; i++) cin >> knower[i];
    for (int i = 0; i < M; i++) {
        int n, h; cin >> n >> h;
        group.push_back(h);
        while (--n) {
            int t; cin >> t;
            Union(h, t);
        }
    }

    for (int i = 0; i < K; i++) true_party.insert(Find(knower[i]));
    for (int i : group) if (true_party.find(Find(i)) != true_party.end()) answer--;
    cout << answer;
    
    return 0;
}