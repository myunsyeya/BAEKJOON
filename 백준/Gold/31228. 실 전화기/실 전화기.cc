#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

ll gcd(ll a, ll b) 
{
    if (!b) return a;
    return gcd(b, a%b);
}

int main()
{
    fio();
    ll N, K; cin >> N >> K;
    ll _gcd = gcd(N, K);

    N /= _gcd; K /= _gcd;
    if (N % K == 0) cout << 0;
    else cout << ((K < N-K) ? N*(K-1) : N*(N-K-1));

    return 0;
}