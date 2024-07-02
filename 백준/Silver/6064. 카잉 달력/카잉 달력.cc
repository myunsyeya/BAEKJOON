#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int gcd(int a, int b) 
{
    if (!b) return a;
    return gcd(b, a%b);
}

int main()
{
    fio();
    int T; cin >> T;
    while (T--) {
        int M, N, x, y; cin >> M >> N >> x >> y;
        int k = -1;
        // (k-1) % M + 1 = x -> k = qM + x
        // (k-1) % N + 1 = y -> k = pN + y
        for (int i = x; i <= M*N; i+=M) {
            if ((i-1) % N + 1 == y) { k = i; break; }
        }
        cout << k << '\n';
    }

    return 0;
}