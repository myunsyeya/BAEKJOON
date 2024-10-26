#include <iostream>
#include <vector>

using namespace std;

#define fio() ios_base::sync_with_stdio(0), cin.tie(0)

int main()
{
    fio();

    string s, t;
    while (cin >> s >> t) {
        int i = 0;
        int j = 0;
        
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j++]) i++;
        }
        if (i == s.length()) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}