#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N, K;
    cin >> N >> K;
    vector<int> stk;
    while (N--) {
        char i;
        cin >> i;
        i = i-'0';
        while (K && !stk.empty() && stk.back() < i) { stk.pop_back(); K--; }
        stk.push_back(i);
    }
    while (K && !stk.empty()) { stk.pop_back(); K--; }
    for (int i : stk) cout << i;
    return 0;
}