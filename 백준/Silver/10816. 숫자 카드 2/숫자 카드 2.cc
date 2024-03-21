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
        int le, ri, ub, lb;
        le = 0;
        ri = n.size() - 1;
        ub = n.size();
        while (le <= ri) {
            int md = (le + ri) >> 1;
            if (n[md] > m)
            {
                ri = md - 1;
                ub = md;
            } else le = md + 1;
        }
        le = 0, ri = n.size()-1;
        lb = n.size();
        while (le <= ri) {
            int md = (le + ri) >> 1;
            if (n[md] >= m)
            {
                ri = md - 1;
                lb = md;
            } else le = md + 1;
        }
        cout << ub - lb << ' ';
    }

    return 0;
}