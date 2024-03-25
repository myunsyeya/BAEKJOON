#include <iostream>
#include <algorithm>
#include <vector>

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
#define __ABS(x) (((x) < 0) ? -(x) : (x))

using namespace std;

typedef long long ll;

vector<ll> toset;

int main()
{
    fio();
    int n;
    ll d1, e, d2; // delta, epsilon

    cin >> n;
    d1 = e = d2 = 1 << 30;
    while (n--)
    {
        int x;
        cin >> x;
        toset.push_back(x);
    }
    sort(toset.begin(), toset.end());
    for (int i = 0; i < toset.size(); i++)
    {
        for (int j = toset.size() - 1; j > i; j--)
        {
            int left, right;
            left = i + 1;
            right = j - 1;
            while (left <= right)
            {
                int mid = (left + right) >> 1;
                ll mix = toset[i] + toset[mid] + toset[j];
                if (__ABS(mix) <= __ABS(d1 + e + d2))
                {
                    d1 = toset[i];
                    e = toset[mid];
                    d2 = toset[j];
                }
                if (mix <= 0)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
    }
    cout << d1 << ' ' << e << ' ' << d2;
    return 0;
}