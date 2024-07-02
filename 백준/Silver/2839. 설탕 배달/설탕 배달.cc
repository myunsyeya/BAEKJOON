#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N; cin >> N;
    int pos = -1;
    for (int i = N/5; i >= 0; i--) {
        if ((N-i*5) % 3 == 0) {
            pos = (i + (N-i*5)/3);
            break;
        }
    }
    cout << pos;
    return 0;
}