#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)


void solve()
{
    map<string, int> clothes;
    int n, comb;
    cin >> n;
    while (n--) {
        string str;
        cin >> str; cin >> str;
        clothes[str]++;
    }
    comb = 1;
    for (auto i : clothes) comb *= i.second+1;
    cout << comb - 1 << '\n';
}

int main()
{
    fio();
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}