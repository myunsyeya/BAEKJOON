#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        int M, N, x, y;
        // K mod M = x - 1
        // K mod N = y - 1
        // x` + q1*M = K
        // y` + q2*N = K
        // 어찌됐든 (M, N)은 lcm(M, N) = M*N*gcd(M,N)
        // (x` - y` + q1*M)/N = q2
        cin >> M >> N >> x >> y;
        x--; y--;
        int end = M*N/gcd(M,N); // lcm(M,N)
        int q1=0, q2=-1, k;
        for (; q1*M + x <= end; q1++)
            if ((x - y + q1*M) % N == 0)
            {
                q2 = (x - y + q1*M)/N;
                break;
            }
        if (q2==-1) k = -1;
        else k = x + 1 + q1*M;
        if (x == y) k = x + 1;
        cout << k << '\n';
    }

    return 0;
}