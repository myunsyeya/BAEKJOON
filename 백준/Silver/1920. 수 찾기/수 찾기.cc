#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int N, M, x, m;
    cin >> N;
    while (N--) {
        cin >> x;
        n.push_back(x);
    }
    sort(n.begin(), n.end());
    cin >> M;
    while (M--) {
        cin >> m;
        auto x = (lower_bound(n.begin(), n.end(), m));
        cout <<  ((x != n.end()) && (m == *x)) << '\n';
    }

    return 0;
}