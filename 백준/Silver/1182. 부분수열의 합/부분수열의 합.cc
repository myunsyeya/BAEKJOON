#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int N, S, ans;
vector<int> seq;

void recur(int i, int s)
{
    if (i == N)
    {
        ans += (s == S);
        return;
    }
    recur(i+1, s);
    recur(i+1, s+seq[i]);
}

int main()
{
    fio();
    cin >> N >> S;
    seq.resize(N);
    for (int &x : seq) cin >> x;
    recur(0, 0);
    cout << ans - (S == 0);
    return 0;
}