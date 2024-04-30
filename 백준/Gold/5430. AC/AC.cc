#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

void solve()
{
    /* parsing */
    int N;
    string P, Z;
    cin >> P >> N >> Z;
    deque<int> dq = deque<int>(N);
    for (int i = 0, j = 1, k; i < N; i++, j+=k+1) {
        k = 0;
        while (Z[j+k] >= '0' && Z[j+k] <= '9') k++;
        dq[i] = atoi(Z.substr(j, k).c_str());
    }
    /* parsing end */
    bool rev = false;
    for (char f : P) {
        if (f == 'R') rev ^= true;
        else if (dq.empty()) { cout << "error\n"; return; }
        else (rev) ? dq.pop_back() : dq.pop_front();
    }
    cout << '[';
    if (dq.empty()) { cout << ']' << '\n'; return; }
    while (dq.size() != 1) {
        cout << ((rev) ? dq.back() : dq.front());
        (rev) ? dq.pop_back() : dq.pop_front();
        cout << ',';
    }
    cout << dq.front() << ']' << '\n';
}

int main()
{
    fio();
    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}