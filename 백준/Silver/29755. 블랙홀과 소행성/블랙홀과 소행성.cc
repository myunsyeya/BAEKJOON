#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(false), cin.tie(nullptr)

int main()
{
    fio();

    // 블랙홀을 정렬하고 그 중 소행성의 위치를 찾는 느낌으로 나아가면,
    // w|b-a|가 최소가 되는, 즉 |b-a|가 최소인 값을 가질 수 있다.
    int N, M; cin >> N >> M;
    vector<int> B(N);
    for (int& b : B) cin >> b;
    vector<pair<int,int>> C(M); // (a, w)
    for (auto& c : C) cin >> c.first >> c.second;

    sort(B.begin(), B.end());

    int P = 0;
    for (auto c : C) {
        int p = (int)1e9;
        int left = 0;
        int right = B.size()-1;
        
        while (left <= right) {
            int mid = (left+right) >> 1;
            p = min(p, abs(B[mid]-c.first)*c.second);
            if (B[mid] > c.first) right = mid-1;
            else left = mid+1;
        }
        P = max(P, p);
    }
    cout << P;
    return 0;
}