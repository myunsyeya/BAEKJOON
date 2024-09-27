#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fio();

    int N; cin >> N;
    vector<int> A(N),B(N),D(N);
    for (int& a : A) cin >> a;
    for (int& b : B) cin >> b;
    for (int i = 0; i < N; i++) D[i] = A[i]-B[i];
    int Q; cin >> Q;
    vector<int> W(Q);
    for (int& w : W) cin >> w;

    for (int i = 1; i < D.size(); i++) {
        if (D[i] > D[i-1]) D[i] = D[i-1];
    }
    for (int w : W) { 
        if (w <= D[N-1]) { cout << N << '\n'; continue; }
        if (w > D[0]) { cout << 0 << '\n'; continue; }
        int left = 0;
        int right = N-1;
        int lb = 0;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (w > D[mid]) right = mid-1;
            else { lb = mid; left = mid+1; };
        }
        cout << (lb+1) << '\n';
    }

    return 0;
}