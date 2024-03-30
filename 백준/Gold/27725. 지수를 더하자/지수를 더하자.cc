#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

vector<int> prime;

int main()
{
    fio();

    int n;
    long long k, b;
    cin >> n;
    prime.resize(n);
    for (int& x : prime) 
        cin >> x;
    cin >> k;
    b = 0;

    for (int p : prime) {
        long long temp = p;
        while (temp <= k) {
            b += k/temp;
            temp *= p;
        }
    }
    cout << b;

    return 0;
}