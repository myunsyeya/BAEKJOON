#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

vector<int> series;
bool chk[51] = { true, };

bool check()
{
    bool gap = false;
    
    for (bool c : chk) {
        if (c && gap) return false;
        gap |= !c; 
    }
    return true;
}

bool back(string s)
{
    if (s == "") return check();
    
    int num1 = s[0] - '0';
    if (!chk[num1]) {
        series.push_back(num1);
        chk[num1] = true;
        if (back(s.substr(1))) return true;
        series.pop_back();
        chk[num1] = false;
    }

    if (s.length() > 1) {
        int num2 = stoi(s.substr(0, 2));
        if (num2 <= 50 && !chk[num2]) {
            series.push_back(num2);
            chk[num2] = true;
            if (back(s.substr(2))) return true;
            series.pop_back();
            chk[num2] = false;
        }
    }
    return false;
}

int main()

{
    fio();

    string s; cin >> s;
    back(s);
    for (int s : series) cout << s << ' ';

    return 0;
}

