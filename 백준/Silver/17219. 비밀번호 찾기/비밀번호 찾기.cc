#include <iostream>
#include <vector>
#include <map>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N, M;
    cin >> N >> M;
    map<string, string> passwd;
    while (N--) {
        string str;
        cin >> str;
        cin >> passwd[str];
    }
    while (M--) {
        string str;
        cin >> str;
        cout << passwd[str] << '\n';
    }
    return 0;
}