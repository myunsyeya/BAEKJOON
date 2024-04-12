#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    string str, exploit;
    stack<char> s;
    stack<char> temp;
    cin >> str >> exploit;
    
    reverse(exploit.begin(), exploit.end());
    for (char c : str) {
        s.push(c);
        if (s.size() >= exploit.size())
        {
            for (char e : exploit) {
                if (s.top() == e)
                {
                    temp.push(s.top());
                    s.pop();
                } else { 
                    while(!temp.empty()) { s.push(temp.top()); temp.pop(); } 
                    break; 
                }
            }
            while (!temp.empty()) temp.pop();
        }
    }
    if (s.empty()) cout << "FRULA";
    while (!s.empty()) { temp.push(s.top()); s.pop(); }
    while (!temp.empty()) { cout << temp.top(); temp.pop(); }
    return 0;
}