#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int __gcd(int a, int b) {
    if (!b) return a;
    return __gcd(b, a%b);
}

int main()
{
    int a, b, gcd, lcm;
    cin >> a >> b;

    gcd = (a<b) ? __gcd(b,a) : __gcd(a,b);
    lcm = a*b/gcd;
    cout << gcd << '\n' << lcm;
    return 0;
}