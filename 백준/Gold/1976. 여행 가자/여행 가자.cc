#include <iostream>

using namespace std;

const int MAX_ELEMENT_SIZE = 201;

int parent[MAX_ELEMENT_SIZE];

inline void MakeSet(int max)
{
    for (int i = 1; i < max + 1; i++) parent[i] = i;
}

int Find(int element)
{
    if (parent[element] == element) return element;
    return parent[element] = Find(parent[element]);
}

inline void Union(int in_set, int element)
{
    parent[Find(element)] = Find(in_set);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, M, tkn, dest;
    cin >> N >> M;
    MakeSet(N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tkn;
            if (tkn) Union(i, j);
        }
    }
    cin >> tkn;
    for (int i = 0; i < M - 1; i++) {
        cin >> dest;
        if (Find(tkn) != Find(dest)) {
            cout << "NO" << '\n';
            goto END;
        }
    }
    cout << "YES" << '\n';
END:
    return 0;
}