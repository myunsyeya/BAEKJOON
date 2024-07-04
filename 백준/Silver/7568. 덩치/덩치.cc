#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N; cin >> N;
    vector<pair<int,int>> human(N);
    vector<int> score(N);
    for (auto& h : human) cin >> h.first >> h.second;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && human[i].first > human[j].first && human[i].second > human[j].second) score[j]++;
        }
    }
    for (int s : score) cout << (s+1) << ' ';

    return 0;
}