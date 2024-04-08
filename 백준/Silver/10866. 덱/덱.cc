#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N;
    deque<int> q;
    cin >> N;
    while (N--) {
        int x;
        string opcode;
        cin >> opcode;
        if (opcode == "push_front") 
        {
            cin >> x;
            q.push_front(x);
        } else if (opcode == "push_back") {
            cin >> x;
            q.push_back(x);
        } else if (opcode == "pop_front") {
            if (q.empty()) cout << "-1\n";
            else { cout << q.front() << '\n'; q.pop_front(); }
        } else if (opcode == "pop_back") {
            if (q.empty()) cout << "-1\n";
            else { cout << q.back() << '\n'; q.pop_back(); }
        } else if (opcode == "size") {
            cout << q.size() << '\n';
        } else if (opcode == "empty") {
            cout << q.empty() << '\n';
        } else if (opcode == "front") {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << '\n';
        } else {    /* back() */
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << '\n';
        }
    }

    return 0;
}