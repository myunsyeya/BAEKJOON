#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

bool MO[30];
vector<char> hint;
int L, C;


void recur(int i, int mo, int ja, string &passwd)
{
    if (mo + ja == L)
    {
        if (mo >= 1 && ja >= 2) cout << passwd << '\n';
        return;
    }
    if (i == C) return;
    passwd.push_back(hint[i]);
    if (MO[hint[i]-'a']) recur(i + 1, mo+1, ja, passwd);
    else recur(i+1, mo, ja+1, passwd);
    passwd.pop_back();
    recur(i + 1, mo, ja, passwd);
}

int main()
{
    fio();
    string s;
    cin >> L >> C;
    hint.resize(C);
    for (char& c : hint) cin >> c;
    sort(hint.begin(), hint.end());
    MO['a' - 'a'] = MO['e' - 'a'] = MO['i' - 'a'] = MO['o' - 'a'] = MO['u' - 'a'] = true;
    recur(0, 0, 0, s);
    return 0;
}