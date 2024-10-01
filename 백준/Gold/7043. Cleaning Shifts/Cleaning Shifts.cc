#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();

    int N, T; cin >> N >> T;
    vector<pair<int,int>> cow(N);
    for (auto& c : cow) cin >> c.first >> c.second;

    sort(cow.begin(), cow.end(), [] (auto a, auto b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int answer = 0;
    int currentEnd = 0;
    int nextEnd = 0;
    int i = 0;

    while (currentEnd < T) {
        while (i < N && cow[i].first <= currentEnd + 1) {
            nextEnd = max(nextEnd, cow[i++].second);
        }
        if (nextEnd == currentEnd) { answer = -1; break; }
        currentEnd = nextEnd;
        answer++;
    }
    cout << answer;

    return 0;
}