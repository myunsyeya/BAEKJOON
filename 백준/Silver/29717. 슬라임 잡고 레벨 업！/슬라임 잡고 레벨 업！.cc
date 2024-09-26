#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(false), cin.tie(nullptr)

typedef long long ll;

int main()
{
    fio();

    int T; cin >> T;
    vector<ll> N(T);
    for (ll &n : N) cin >> n;

    for (ll n : N) {
        ll exp = n*(n+1)/2;
        ll left = 0;
        ll right = (int)1e9;
        while (left <= right) {
            ll mid = (left + right) >> 1;
            if (mid*(mid+1) <= exp) left = mid+1;
            else right = mid-1;
        }
        cout << left << '\n';
    }

    return 0;
}