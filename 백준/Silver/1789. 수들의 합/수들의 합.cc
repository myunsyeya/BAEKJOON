#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

typedef long long ll;

int main()
{
    unsigned int s, i;
    cin >> s;
    for (i = 0; i < s; i++, s-=i);
    cout << ((s < i) ? i : s);

    return 0;
}