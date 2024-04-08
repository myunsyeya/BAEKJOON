#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N;
    stack<int> s;
    cin >> N;
    while (N--) {
        int x;
        string opcode;
        cin >> opcode;
        if (opcode == "push") 
        {
            cin >> x;
            s.push(x);
        } else if (opcode == "pop") {
            if (s.empty()) cout << "-1\n";
            else { cout << s.top() << '\n'; s.pop(); }
        } else if (opcode == "size") {
            cout << s.size() << '\n';
        } else if (opcode == "empty") {
            cout << s.empty() << '\n';
        } else {    /* top */
            if (s.empty()) cout << "-1\n";
            else cout << s.top() << '\n';
        }
    }

    return 0;
}