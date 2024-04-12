#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    stack<int> s;
    int K;
    int sum = 0;
    cin >> K;
    while (K--) {
        int x;
        cin >> x;
        if (!x) s.pop();
        else s.push(x);
    }
    while (!s.empty()) { sum += s.top(); s.pop(); }
    cout << sum;
    return 0;
}