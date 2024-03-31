#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
#define MAX ( 32000 ) // sqrt(10^9) = 31622.7...

bool not_prime[MAX];
vector<int> prime;
vector<int> intp;

void sieve()
{
    not_prime[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (not_prime[i]) continue;
        prime.push_back(i);
        for (int j = i * i; j < MAX; j += i) not_prime[j] = 1;
    }
}

bool isPrime(int n)
{
    if (n == 1) return false;
    for (int x : prime) {
        if (x * x > n) break;
        if (n == x) return true;
        if (n % x == 0) return false;
    }
    return true;
}

int power(int a, int b)
{
    if (!b) return 1;
    if (b % 2) return a * power(a, b - 1);
    int half = power(a, b / 2);
    return half * half;
}

int main()
{
    fio();
    int n, max;
    cin >> n;
    max = power(10, n);
    sieve();
    for (int i = power(10, n - 1); i < max; i++) {
        int check = true;
        for (int j = power(10, n - 1); j > 0; j/=10)
            if (!isPrime(i / j))
            {
                check = false;
                break;
            }
        if (check) intp.push_back(i);
    }
    for (int x : intp) cout << x << '\n';
    return 0;
}