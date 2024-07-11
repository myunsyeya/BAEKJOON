#include <stdio.h>

typedef long long ll;

ll __gcd(ll a, ll b)
{
    if (!b) return a;
    return __gcd(b, a%b);
}

int main()
{
    ll a, b;
    scanf(" %lld %lld", &a, &b);
    printf("%lld\n", a*b/__gcd(a, b));
    return 0;
}