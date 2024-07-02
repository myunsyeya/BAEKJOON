#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)
#define ABS(x) ( ((x) > 0) ? (x) : (-(x)) )
// make sure x belong to real number data type.
#define round(x) ( ((x) > 0) ? ((int)(ABS(x) + 0.5)) : (-((int)(ABS(x) + 0.5))) )

int main()
{
    fio();
    int N; cin >> N;
    vector<int> zahlen(N);
    for (int& z : zahlen) cin >> z;
    vector<int> mode;
    int prev, now;
    double sum;

    sort(zahlen.begin(), zahlen.end());
    sum = zahlen[0];
    mode.push_back(zahlen[0]);
    prev = now = 0;
    for (int i = 1; i < N; i++) {
        if (zahlen[i-1] == zahlen[i]) now++;
        else now = 0;
        if (now == prev) mode.push_back(zahlen[i]);
        if (now > prev) { prev = now; mode.clear(); mode.push_back(zahlen[i]); }
        sum += zahlen[i];
    }
    cout << round(sum/N) << '\n';
    cout << zahlen[N/2] << '\n';
    cout << ((mode.size()>1) ? mode[1]: mode[0]) << '\n';
    cout << (zahlen[N-1]-zahlen[0]);
    return 0;
}