#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N = 7;
    int old, now;
    enum order {
        ASCEND, 
        DESCEND, 
        MIX,
    } _order = MIX;
    cin >> old;
    while (N--) {
        cin >> now;
        if (old > now && _order == ASCEND) { _order = MIX; break; }
        else if (old < now && _order == DESCEND) { _order = MIX; break; }
        else _order = (old < now) ? ASCEND : DESCEND;
        old = now;
    }
    if (_order == ASCEND) cout << "ascending";
    else if (_order == DESCEND) cout << "descending";
    else cout << "mixed";
    return 0;
}