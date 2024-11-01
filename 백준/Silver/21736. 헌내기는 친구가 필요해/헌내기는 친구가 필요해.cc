#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

typedef long long ll;

void test_print(vector<vector<char>> map)
{
    for (auto row : map) {
        for (auto c : row) cout << c;
        cout << '\n';
    }
}

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main()
{
    fio();

    int N, M; cin >> N >> M;
    queue<pair<int,int>> q;
    vector<vector<char>> map(N+2);
    for (int i = 0; i < N+2; i++) map[i].assign(M+2, 0);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') q.push({i, j});
        }
    }

    int answer = 0;
    while (!q.empty()) {
        pair<int,int> cur = q.front(); q.pop();
        int nx, ny;
        for (int i = 0; i < 4; i++) {
            tie(ny, nx) = cur;
            nx += dx[i];
            ny += dy[i];
            if (map[ny][nx] != 'X' && map[ny][nx] != 0) {
                if (map[ny][nx] == 'P') answer++;
                map[ny][nx] = 'X';
                q.push({ny, nx});
            }
        }
    }
    
    if (!answer) cout << "TT";
    else cout << answer;

    return 0;
}