#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N;
    cin >> N;
    N /= 4;
    while (N--) cout << "long ";
    cout << "int";
    return 0;
}