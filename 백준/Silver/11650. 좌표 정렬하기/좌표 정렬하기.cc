#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

ostream& operator<<(ostream& o, const pair<int,int>& p)
{
    return o << p.first << " " << p.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N;
    int x, y;
    cin >> N;
    while (N--) {
        cin >> x >> y;
        v.push_back({ x, y });
    }
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](const pair<int, int>& p) {
        cout << p << "\n";
        });
    return 0;
}