#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int num[101];

int gcd(int a, int b) 
{
    if (!b) return a;
    return gcd(b, a%b);
}

int main()
{
    fio();
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> num[i];
        long long sum = 0;

        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                sum += gcd(num[i], num[j]); 
            }
        }
        cout << sum << '\n';
    }
    return 0;
}