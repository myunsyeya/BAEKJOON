#include <iostream>

using namespace std;

const int MAX_ELEMENT_SIZE = 1e6 + 1;

int parent[MAX_ELEMENT_SIZE];

void MakeSet(int max)
{
    for (int i = 1; i < max + 1; i++)
        parent[i] = i;
}

int Find(int element)
{
    if (parent[element] == element)
        return element;
    return parent[element] = Find(parent[element]);
}

void Union(int in_set, int element)
{
    parent[Find(element)] = Find(in_set);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    MakeSet(n);
    for (int i = 0; i < m; i++) {
        int tkn, a, b;
        cin >> tkn >> a >> b;
        if (tkn) {
            if (Find(a) == Find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            Union(a, b);
    }
    return 0;
}