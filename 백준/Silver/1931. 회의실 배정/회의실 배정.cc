#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();
    int N; cin >> N;
    vector<tuple<int,int>> I(N);
    for (auto &i : I) cin >> get<0>(i) >> get<1>(i);

    sort(I.begin(), I.end(), [](auto a, auto b){
        if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
    });
    int max, old; max = 0; old = -1;
    for (auto i : I) {
        if (old <= get<0>(i)) { max++; old = get<1>(i); } 
    }

    cout << max;
    return 0;
}