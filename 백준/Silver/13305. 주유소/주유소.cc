#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();
    int N; cin >> N;
    long long answer = 0;
    int min_price = 1e9;
    vector<int> length(N-1);
    vector<int> price(N);
    for (int &l : length) cin >> l;
    for (int &p : price) cin >> p;

    for (int i = 0; i < N-1; i++) {
        min_price = min(min_price, price[i]);
        answer += (long long)min_price * length[i];
    }
    cout << answer;
    return 0;
}