#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

bool isPrime(int n) 
{
    if (n == 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

ll pow(int n, int r) 
{
    if (!r) return 1;
    return n*pow(n, r-1);
}

int main()
{
    fio();
    int N; cin >> N;

    int p = pow(10, N-1);
    int i = p;
    while (i < p*10) {
        for (int j = N; j > 0; j--) {
            if (!isPrime(i/pow(10, j-1))) { i += pow(10, j-1); goto fail; }
        }
        cout << i << '\n';
        i++;
fail:;
    }
    return 0;
}