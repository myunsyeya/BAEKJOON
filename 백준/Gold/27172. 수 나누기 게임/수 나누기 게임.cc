#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

vector<int> player;
bool check[1 << 20];
int score[1 << 20];

void solve(int N)
{
    for (int i : player)
    {
        if (!check[i]) continue;
        for (int j = i+i; j < N; j += i) {
            if (check[j])
            {
                score[i]++;
                score[j]--;
            }
        }
    }
}

int main()
{
    fio();
    int n;
    cin >> n;
    player.resize(n);
    for (int &x : player) cin >> x;
    for (int x : player) check[x] = true;
    solve(1 << 20);
    for (int x : player) cout << score[x] << ' ';

    return 0;
}