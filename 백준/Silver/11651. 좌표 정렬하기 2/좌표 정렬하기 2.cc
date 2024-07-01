#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N; 
    cin >> N;
    vector<pair<int, int>> I(N);
    for (auto &i : I) cin >> i.first >> i.second;

    sort(I.begin(), I.end(), [] (const auto &a, const auto &b) {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });

    for (const auto &i : I) cout << i.first << ' ' << i.second << '\n';

    return 0;
}
