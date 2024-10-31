#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();

    int N; cin >> N;
    vector<int> out(N);

    int go; cin >> go;
    int cnt = 0;
    if (go-1 == 0 && ++cnt) out[0] = 2;
    else out[0] = go;
    for (int i = 1; i < N; i++) {
        cin >> go;
        if (go-1 == i && ++cnt) out[i] = go-1;
        else out[i] = go;
    }

    cout << cnt << '\n';
    for (int i : out) cout << i << ' ';

    return 0;
}