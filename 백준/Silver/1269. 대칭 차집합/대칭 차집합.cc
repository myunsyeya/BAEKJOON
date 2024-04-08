#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

set<int> A, B;

int main()
{
    int NA, NB;
    int cnt;
    cin >> NA >> NB;
    cnt = 0;
    for (int i = 0; i < NA; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }
    for (int i = 0; i < NB; i++) {
        int x;
        cin >> x;
        B.insert(x);
    }
    for (int x : A) if (B.find(x) != B.end()) cnt++;
    cout << A.size() + B.size() - 2*cnt;
    return 0;
}