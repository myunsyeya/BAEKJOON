#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX_G 100001

int parent[MAX_G];

int _find(int u)
{
    if (u == parent[u]) return u;
    return parent[u] = _find(parent[u]);
}

void _union(int u, int v)
{
    u = _find(u);
    v = _find(v);
    if (u == v) { parent[v] = u-1; return; }
    parent[v] = u;
}

int main()
{
    fio();
    int G, P, dock = 0;
    cin >> G >> P;
    for (int i = 0; i < MAX_G; i++) parent[i] = i;

    while (P--) {
        int g;
        cin >> g;
        if (_find(g) == 0) break;
        dock++;
        _union(_find(g)-1, g);
    }
    cout << dock;
    return 0;
}