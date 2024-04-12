#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    char buf[128];

    while (1) {
        stack<char> s;   
        cin.getline(buf, 128);
        if (buf[0] == '.') break;
        for (int i = 0; buf[i]; i++) {
            if (buf[i] == '[' || buf[i] == '(') s.push(buf[i]);
            if (buf[i] == ']')
            {
                if (s.empty()) s.push('!');
                if (s.top() != '[') break;
                s.pop();
            }
            if (buf[i] == ')')
            {
                if (s.empty()) s.push('!');
                if (s.top() != '(') break;
                s.pop();
            }
        }
        if (s.empty()) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}