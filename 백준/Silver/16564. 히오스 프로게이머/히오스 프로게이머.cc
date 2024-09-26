#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fio();

    int N, K; cin >> N >> K;
    vector<int> level(N);
    for (int &l : level) cin >> l;

    sort(level.begin(), level.end());

    int left = 0;
    int right = level[0]+K;
    int lb = 0;//답
    
    while (left <= right) {
        int mid = (left+right) >> 1;
        long long sum = 0;
        int up = mid;

        for (int i = 0; i < N && level[i] < up; i++) sum += up - level[i];
        if (sum > K) right = mid-1;
        else { lb = mid; left = mid+1; }
    }

    cout << lb;

    return 0;
}