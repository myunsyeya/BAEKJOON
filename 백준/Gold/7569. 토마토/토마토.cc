#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define fio() ios_base::sync_with_stdio(0), cin.tie(0)

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    fio();
    int M, N, H; cin >> M >> N >> H;
    int answer = 0;
    vector<vector<vector<int>>> box(H+2, vector<vector<int>>(N+2, vector<int>(M+2, -1)));
    queue<tuple<int, int, int>> q;

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1) q.push({i, j, k});
            }
        }
    }

    while(!q.empty()) {
        tuple<int, int, int> front = q.front(); q.pop();
        int z = get<0>(front), x = get<1>(front), y = get<2>(front);
        for(int i = 0; i < 6; i++) {
            int nz = z + dz[i], nx = x + dx[i], ny = y + dy[i];
            if(box[nz][nx][ny] == 0) {
                box[nz][nx][ny] = box[z][x][y] + 1;
                q.push({nz, nx, ny});
            }
        }
    }

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= M; k++) {
                if(box[i][j][k] == 0) { cout << -1; return 0; }
                answer = max(answer, box[i][j][k]);
            }
        }
    }
    cout << answer - 1;

    return 0;
}