#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();
    int N, K; cin >> N >> K;
    vector<pair<int,int>> jewel(N);
    vector<int> C(K);
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) cin >> jewel[i].first >> jewel[i].second;
    for (int i = 0; i < K; i++) cin >> C[i];

    sort(jewel.begin(), jewel.end());
    sort(C.begin(), C.end());
    long long max_V = 0;
    size_t j = 0;
    for (int i = 0; i < K; i++) {
        for (; j < jewel.size(); j++) {
            if (C[i] >= jewel[j].first) pq.push(jewel[j].second);
            else break;
        }
        if (!pq.empty()) { max_V += pq.top(); pq.pop(); }
    }
    cout << max_V;
    return 0;
}