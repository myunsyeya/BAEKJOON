#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
    fio();
    int N; cin >> N;
    int count = 0;
    
    for (int i = 5; i <= N; i+=5) {
        int x = i;
        while (x % 5 == 0) { x /= 5; count++; }
    }
    cout << count;
    return 0;
}