#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define ABS(x) ( ((x) > 0) ? (x) : (-(x)) )

bool button[10];

int main()
{
    fio();
    int N, M; cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int b; cin >> b;
        button[b] = true;
    }

    int direct = (button[0]) ? -100 : 0;
    int radix = 0;

    for (int i = 1; i <= (int)1e6; i++) {
        for (int j = i; j; j/=10) {
            if (button[j%10]) goto fail;
        }
        if (ABS(N-i) < ABS(N-direct)) direct = i;
fail:;
    }
    
    if (!direct) radix = 1;
    else for (int i = direct; i; i/=10) radix++;

    cout << ((ABS(N-100) < ABS(N-direct)+radix) ? ABS(N-100) : ABS(N-direct)+radix);
    return 0;
}