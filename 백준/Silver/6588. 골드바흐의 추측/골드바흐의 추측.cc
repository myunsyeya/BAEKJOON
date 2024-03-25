#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
#define MAX ( 1 << 20 )

bool not_prime[MAX];
vector<int> prime;

void sieve()
{
    not_prime[1] = 1;
    for (int i = 2; i*i < MAX; i++) {
        if (not_prime[i]) continue;
        prime.push_back(i);
        for (int j = i*i; j < MAX; j+=i) not_prime[j] = 1;
    }
}

void solve() 
{
    int N;
    cin >> N;

    if (!N) exit(0);

    for (int x:prime) {
        if (!not_prime[N-x]) {
            cout << N << " = " << x << " + " << N - x << '\n'; 
            return;
        }
    }
}

int main()
{
    fio();
    sieve();
    while(1) solve();
    return 0;
}