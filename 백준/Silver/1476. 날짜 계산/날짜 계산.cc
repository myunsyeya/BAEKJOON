#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int E, S, M; cin >> E >> S >> M;
    // 15*28*19 = 7980
    int year = 1;
    for (int i=1, j=1, k=1; i!=E || j!=S || k!=M; i++,j++,k++, year++) {
        if (i == 15) i = 0;
        if (j == 28) j = 0;
        if (k == 19) k = 0;
    }
    cout << year;
    return 0;
}