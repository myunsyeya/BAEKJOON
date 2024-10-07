#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int bit1Count(short step)
{
    step = (step & 0x5555) + ((step >> 1) & 0x5555);
    step = (step & 0x3333) + ((step >> 2) & 0x3333);
    step = (step & 0x0F0F) + ((step >> 4) & 0x0F0F);
    step = (step & 0x00FF) + ((step >> 8) & 0x00FF);

    return step;
}

int main()
{
    fio();

    int n, k; cin >> n >> k;
    vector<short> exam(n);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int tmp = 0;
        for (int x = 0; x < k; x++) {
            if (s[x] == 'F') tmp++;
            else if (s[x] == 'T') exam[i] |= 1<<(k-x-1);
        }
    }
    int answer = 0;
    for (int i = 0; i < (1<<k); i++) {
        int min = 11;
        for (int j = 0; j < n; j++) {
            short e = exam[j];
            for (int b = 0; b < k; b++) { 
                if (i & (1<<b)) e ^= 1 << b;
            }
            if (bit1Count(e) < min) min = bit1Count(e);
        }
        if (min > answer) answer = min;
    }
    cout << answer;
    return 0;
}