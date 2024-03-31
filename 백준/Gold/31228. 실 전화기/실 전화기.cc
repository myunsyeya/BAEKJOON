#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

typedef long long ll;

ll __gcd(ll a, ll b) {
	if (!b) return a;
	return __gcd(b, a % b);
}

int main()
{
    fio();
    ll n, k;
    cin >> n >> k;
    ll gcd = __gcd(n, k);
    n /= gcd; k /= gcd;
    if (n % k == 0) cout << 0;
    else cout << ((k < (n+1)/2) ? (n*(k-1)) : (n*(n-k-1)));

    return 0;
}