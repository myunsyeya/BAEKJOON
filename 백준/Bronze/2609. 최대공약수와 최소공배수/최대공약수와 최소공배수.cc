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
    int A, B; cin >> A >> B;
    cout << gcd(A, B) << '\n' << A*B/gcd(A,B);

    return 0;
}