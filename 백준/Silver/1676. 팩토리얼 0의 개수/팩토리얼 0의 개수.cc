// Example program
#include <iostream>
#include <vector>

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

using namespace std;

int main()
{
    fio();
    int n, two, five;
    cin >> n;
    two = five = 0;
    
    for (int i = 2; i <= n; i++) {
        int x = i;
        while (x % 2 == 0) {
            x /= 2; two++;   
        }
        while (x % 5 == 0) {
            x /= 5; five++;
        }
    }
    cout << ((two < five) ? two: five);
    
    return 0;
}