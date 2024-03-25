#include <iostream>
#include <vector>

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
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
    while (n--) {
        int x;
        cin >> x;
        toset.push_back(x);
    }
    for (int i = 0; i < toset.size(); i++) {
        int left, right;
        left = i + 1;
        right = toset.size() - 1;
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