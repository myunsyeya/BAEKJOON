#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int priority[128];

stack<char> oprt;
stack<char> oprd;

int main()
{
    string exp;
    cin >> exp;

    priority['+'] = priority['-'] = 1;
    priority['*'] = priority['/'] = 2;
    priority['('] = 3;
    for (char c : exp) {
        if (c == ')')
        {
            while (!oprt.empty() && oprt.top() != '(') {
                cout << oprt.top(); oprt.pop();
            }
            oprt.pop();
            continue;
        }
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(')
        {
            if (oprt.empty()) oprt.push(c);
            else if (priority[c] > priority[oprt.top()]) oprt.push(c);
            else {
                while (!oprt.empty() && priority[c] <= priority[oprt.top()]) { 
                    if (oprt.top() == '(') break;
                    cout << oprt.top(); 
                    oprt.pop(); 
                }
                oprt.push(c);
            }
        }
        else cout << c;
    }
    while (!oprt.empty()) {
        cout << oprt.top(); oprt.pop();
    }

    return 0;
}