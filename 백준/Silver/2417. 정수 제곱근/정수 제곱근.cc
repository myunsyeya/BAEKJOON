#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ull n;
    ull left, right, mid, lower_bound;
    
    cin >> n;
    left = 0;
    right = lower_bound = n < 3037000500ll? n: 3037000500ll; // similarly, sqrt((1ULL << 63) - 1)
    // q^2 >= n 이므로 lower bound를 구하면 됨.
    while (left <= right) {
        mid = (left + right) >> 1;
        if (mid * mid >= n) 
        {
            if (!mid)
                break;
            right = mid - 1;
            lower_bound = mid;
        } else left = mid + 1;
    }
    cout << lower_bound;
    return 0;
}