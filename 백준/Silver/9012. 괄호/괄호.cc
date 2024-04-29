#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

void solve()
{
    string S;
    cin >> S;
    int n = S.size();
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        if (S[i] == '(') stk.push(i);
        else if (stk.empty()) { cout << "NO\n"; return; }
        else stk.pop();   
    }
    if (!stk.empty()) { cout << "NO\n"; return; }
    cout << "YES\n";
}

int main()
{
    fio();
    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}