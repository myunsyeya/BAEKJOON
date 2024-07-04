#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int map[501][501];

int main()
{
    fio();
    int N, M, B; cin >> N >> M >> B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> map[i][j];
    }
    int time = (int)6.4*1e7;
    int opt_height;

    for (int h = 0; h <= 256; h++) {
        int now = 0;
        int inv = B;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] > h) { 
                    inv += map[i][j]-h;
                    now += 2*(map[i][j]-h);
                } 
                if (map[i][j] < h) {
                    inv -= h-map[i][j];
                    now += h-map[i][j];
                }
            }
        }
        if (inv >= 0 && time >= now) { time = now; opt_height = h; }
    }

    cout << time << ' ' << opt_height;
    return 0;
}