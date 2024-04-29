#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

typedef long long ll;

int main()
{
    fio();
    ll depth, old_d, sum;
    string S;
    depth = old_d = -1;
    sum = 0;
    cin >> S;
    for (char c : S) {
        if (c == '(') old_d = depth++;
        else { sum += (old_d < depth) ? depth : 0; depth--; }
    }
    cout << sum;
    return 0;
}