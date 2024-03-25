#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
#define MAX ( 1 << 10 )

bool not_prime[MAX];
vector<int> prime;

void sieve()
{
    not_prime[1] = 1;
    for (int i = 2; i*i < MAX; i++) {
        if (not_prime[MAX]) continue;
        prime.push_back(i);
        for (int j = i*i; j < MAX; j+=i) not_prime[j] = 1;
    }
}

int main()
{
    fio();
    sieve();
    int n, sum;
    cin >> n;
    sum = 0;

    while (n--) {
        int x;
        cin >> x;
        if (!not_prime[x]) sum++;
    }
    cout << sum;
}