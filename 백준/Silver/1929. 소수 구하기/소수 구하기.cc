#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
#define MAX ( 1 << 21 )

int not_prime[MAX];
vector<int> prime;

void sieve()
{
    not_prime[1] = 1;
    for (int i = 2; i*i < MAX; i++) {
        if (not_prime[i]) continue;
        for (int j = i*i; j < MAX; j+=i) not_prime[j] = 1;
    }
}

int main()
{
    fio();
    sieve();
    int m, n;
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if(not_prime[i]) continue;
        cout << i << '\n';
    }
    return 0;
}