#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int& a : A) cin >> a;
    cin >> M;
    vector<int> X(M);
    for (int& x : X) cin >> x;

    sort(A.begin(), A.end());
    for (const int& x : X) {
        auto lb = lower_bound(A.begin(), A.end(), x);
        auto ub = upper_bound(A.begin(), A.end(), x);
        cout << ((lb != A.end()) ? ub-lb : 0) << ' ';
    }
    return 0;
}