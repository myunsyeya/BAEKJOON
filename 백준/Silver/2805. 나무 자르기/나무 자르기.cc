#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N, M; cin >> N >> M;
    vector<int> wood(N);
    for (int& w : wood) cin >> w;

    int le = 0;
    int ri = (int)1e9;
    int h;

    while (le <= ri) {
        int mid = ri - (ri-le)/2;
        long long sum = 0;
        for (const int& w : wood) sum += (w-mid > 0) ? w-mid : 0;
        if (sum >= M) {
            h = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }
    
    cout << h;

    return 0;
}