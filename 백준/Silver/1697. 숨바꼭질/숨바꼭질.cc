#include <iostream>
#include <queue>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

#define MIN 0
#define MAX ((int)1e5)

int visited[MAX+1];

int main()
{
    fio();

    int N, K; cin >> N >> K;
    pair<int, int> X;
    queue<pair<int, int>> q;
    q.push({N, 0});

    while(!q.empty()) {
        X = q.front(); q.pop();
        int &x = X.first;
        if (visited[x]) continue;
        if (x == K) break;
        visited[x] = 1;
        
        if (x-1 >= MIN) q.push({x-1, X.second+1});
        if (x+1 <= MAX) q.push({x+1, X.second+1});
        if (x*2 <= MAX) q.push({x*2, X.second+1});
    }
    cout << X.second;

    return 0;
}