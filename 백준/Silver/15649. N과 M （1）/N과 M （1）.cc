#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int N, M;
bool parent[9];
vector<int> series;

void recursion()
{
    // base case
    if(series.size() == M) {
        for (int x : series) cout << x << ' ';
        cout << '\n'; return;
    }
    for (int i = 1; i <= N; i++) {
        if (parent[i]) continue;
        series.push_back(i);
        parent[i] = true;
        recursion();
        series.pop_back();
        parent[i] = false;
    }
}

int main()
{
    fio();
    vector<int> a;
    cin >> N >> M;
    recursion();
    return 0;
}