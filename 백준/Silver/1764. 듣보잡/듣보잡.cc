#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N, M;
    cin >> N >> M;
    vector<string> output;
    map<string, int> no_listening_seeing;
    for (int i = 0; i < N + M; i++) {
        string str;
        cin >> str;
        no_listening_seeing[str]++;
    }
    for (auto iter : no_listening_seeing) {
        if (iter.second == 2) output.push_back(iter.first);
    }
    sort(output.begin(), output.end());
    cout << output.size() << '\n';
    for (string str : output) cout << str << '\n';
    return 0;
}