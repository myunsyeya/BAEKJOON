#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

ll pow(int A, int B, int C)
{
    if (!B) return 1;
    if (B%2) return A * pow(A, B-1, C) % C;
    ll half = pow(A, B/2, C) % C;
    return half * half % C;
}

int main()
{
    fio();
    int A, B, C; cin >> A >> B >> C;

    cout << pow(A,B,C);
    return 0;
}