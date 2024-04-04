#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int L, C;
vector<char> hint;
set<string> ans;

void recur(int i, string &passwd)
{
    if (passwd.size() == L)
    {
        int check = 0;
        for (int i = 0; i < L; i++)
            check += passwd[i] == 'a' || passwd[i] == 'e'
            || passwd[i] == 'i' || passwd[i] == 'o' || passwd[i] == 'u';
        if (!check || L - check < 2) return;
        ans.insert(passwd);
    }
    if (i == C) return;
    if (passwd.size() + C - i < L) return;
    passwd.push_back(hint[i]);
    recur(i + 1, passwd);
    passwd.pop_back();
    recur(i + 1, passwd);
}

int main()
{
    fio();
    string s;
    cin >> L >> C;
    hint.resize(C);
    for (char& c : hint) cin >> c;
    sort(hint.begin(), hint.end());
    recur(0, s);
    for (string s : ans) cout << s << '\n';
    return 0;
}