// Example program
#include <iostream>
#include <vector>
#include <algorithm>

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

using namespace std;

vector<int> N;

#define ABS(x) ( ((x) > 0) ? (x) : (-(x)) )
// make sure x belong to real number data type.
#define round(x) ( ((x) > 0) ? ((int)(ABS(x) + 0.5)) : (-((int)(ABS(x) + 0.5))) )

int main()
{
    fio();
    int n;
    cin >> n;
    N.resize(n);
    for (int& x: N) cin >> x;
    
    sort(N.begin(), N.end());
    double sum = 0;
    for (int x : N) sum += x;
    int bias = 4000;
    int freq[8192] = { 0 };
    for (int x : N) freq[bias + x]++;
    
    int mean = round(sum/n);
    int median = N[n/2];
    int mode = 0;
    int max = 0;
    int dup = 0;
    for (int i = -4000; i <= 4000; i++) {
        if (freq[bias + i] > max)
        {
            max = freq[bias + i]; 
            mode = i;
            dup = 0;
        }
        if (freq[bias + i] == max)
        {
            max = freq[bias + i]; 
            mode = i;
            dup++;
        }
    }
    if (dup > 1)
    {
        dup = 0;
        for (int i = -4000; i <= 4000; i++) {
            if (freq[bias + i] == max)
            {
                if (dup) 
                {
                    mode = i; 
                    break;
                }
                dup++;
            }
        }
    }
    int range = N[n - 1] - N[0];
    cout << mean << '\n' << median << '\n' << mode << '\n' << range;
    return 0;
}