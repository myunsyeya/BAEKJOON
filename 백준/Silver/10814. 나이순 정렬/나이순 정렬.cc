#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N; cin >> N;
    vector<pair<int,string>> profile(N);
    for (auto& p : profile) cin >> p.first >> p.second;

    stable_sort(profile.begin(), profile.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    for (const auto& p : profile) cout << p.first << ' ' << p.second << '\n';

    return 0;
}