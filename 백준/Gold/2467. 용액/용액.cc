#include <iostream>
#include <vector>

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)
#define __ABS(x) ( ((x) < 0) ? -(x) : (x) )

using namespace std;

vector<int> toset;

int main()
{
    fio();
    int n;
    int d, e;   // delta, epsilon

    cin >> n;
    d = e = 1000000000;
    toset = vector<int>(n);
    for (int& x : toset) cin >> x;
    for (int i = 0; i < n; i++) {
        int left, right;
        left = i + 1;
        right = n - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            int mix = toset[i] + toset[mid];
            if (__ABS(mix) <= __ABS(d + e))
            {
                d = toset[i];
                e = toset[mid];
            }
            if (mix <= 0) 
                left = mid + 1;
            else 
                right = mid - 1;
        }
    }
    cout << d << ' ' << e;
    return 0;
}