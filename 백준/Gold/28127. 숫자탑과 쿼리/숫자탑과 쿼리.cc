#include <iostream>

using namespace std;

#define SERIES(a, d, n) ( (n)*(2*(a) + ((n)-1)*(d))/2 )

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll q;
    
    cin >> q;
    while (q--) {
        ll n, a, d, x, floor;
        n = (1 << 20); // bded문제: n의 크기를 어떻게 잡아야 항상 x의 최대 10^6을 가리킬까?
        cin >> a >> d >> x;
        ll left, right, mid;
        left = 0;
        right = floor = n;
        while (left <= right) {
            mid = (left + right) >> 1;
            if (SERIES(a, d, mid) <= x)
            {
                floor = mid;
                left = mid + 1;
            } else right = mid - 1;
        }
        if (!(x - SERIES(a, d, floor)))
            cout << floor << ' ' << x - SERIES(a, d, floor - 1) << '\n';
        else 
            cout << floor + 1 << ' ' << x - SERIES(a, d, floor) << '\n';
    }
    
    return 0;
}