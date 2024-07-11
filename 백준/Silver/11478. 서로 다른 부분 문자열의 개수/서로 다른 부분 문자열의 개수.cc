#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{   
    fio();
    string s; cin >> s;
    int n = s.length();

    // make suffix array
    vector<string> suffix(n);
    for (int i = 0; i < n; i++) suffix[i] = s.substr(i, n);
    sort(suffix.begin(), suffix.end());

    // make lcp
    vector<int> lcp(n);
    for (int i = 1; i < n; i++) {
        int idx = 0;
        while (idx < suffix[i-1].length() && idx < suffix[i].length()
        && suffix[i-1][idx] == suffix[i][idx]) lcp[i] = ++idx;
    }

    // numbers of substrings
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += suffix[i].length() - lcp[i];
    cout << cnt;
    return 0;
}