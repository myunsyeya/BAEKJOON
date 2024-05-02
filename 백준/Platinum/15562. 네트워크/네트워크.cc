#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N, M;
    cin >> N >> M;
    vector<int> in(N+1), out(N+1);
    while (M--) {
        int v1, v2;
        cin >> v1 >> v2;
        out[v1]++;
        in[v2]++;
    }
    int network = 0;
    for (int i = 1; i <= N; i++) {
        network += max(0, out[i] - in[i]);
    }
    cout << network;
    return 0;
}