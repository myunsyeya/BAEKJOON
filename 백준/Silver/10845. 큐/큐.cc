#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N;
    queue<int> q;
    cin >> N;
    while (N--) {
        int x;
        string opcode;
        cin >> opcode;
        if (opcode == "push") 
        {
            cin >> x;
            q.push(x);
        } else if (opcode == "pop") {
            if (q.empty()) cout << "-1\n";
            else { cout << q.front() << '\n'; q.pop(); }
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