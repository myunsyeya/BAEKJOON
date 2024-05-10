#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr); } while(0)

int main()
{
    fio();
    int N, v, cnt = 0;
    int A[100];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> v;
    for (int i = 0; i < N; i++) if (A[i] == v) cnt++;
    cout << cnt;

    return 0;
}