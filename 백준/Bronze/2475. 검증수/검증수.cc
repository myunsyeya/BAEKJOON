#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int dec, sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> dec;
        sum += dec*dec;
    }
    cout << (sum%10);
    return 0;
}