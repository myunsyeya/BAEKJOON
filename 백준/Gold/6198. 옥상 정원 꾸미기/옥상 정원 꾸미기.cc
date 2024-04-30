#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N;
    long long sum = 0;
    stack<pair<int,int>> stk; // first := idx, second := value
    cin >> N;
    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        while (!stk.empty() && stk.top().second <= now) { sum += i - 1 - stk.top().first; stk.pop(); }
        stk.push({i, now});
    }
    while (!stk.empty()) { sum += N - 1 - stk.top().first; stk.pop(); }
    cout << sum;
    return 0;
}