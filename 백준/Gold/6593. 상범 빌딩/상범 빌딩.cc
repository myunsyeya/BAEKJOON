#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define fio() cin.tie(nullptr), ios_base::sync_with_stdio(false)

bool visited[32][32][32];
char build[32][32][32];
int dc[6] = { 1, -1, 0, 0, 0, 0 };
int dr[6] = { 0, 0, 1, -1, 0, 0 };
int dl[6] = { 0, 0, 0, 0, 1, -1 };
vector<int> s, e;       // (l, r, c)

int bfs()
{
    queue<vector<int>> q;
    q.push(s);

    while (!q.empty()) {
        vector<int> cx(q.front()); q.pop();
        for (int i = 0; i < 6; i++) {
            vector<int> nx({ cx[0] + dl[i],cx[1] + dr[i],cx[2] + dc[i],cx[3]+1 });
            if (build[nx[0]][nx[1]][nx[2]] == 'E') return nx[3];
            else if (build[nx[0]][nx[1]][nx[2]] == '.' && !visited[nx[0]][nx[1]][nx[2]]) {
                visited[nx[0]][nx[1]][nx[2]] = true;
                q.push(nx);
            }
        }
    }
    return 0;
}

int main()
{
    fio();

    do {
        memset(visited, 0, sizeof(visited));
        memset(build, 0, sizeof(build));
        int L, R, C; cin >> L >> R >> C;
        if (!L && !R && !C) break;

        for (int l = 1; l <= L; l++) {
            for (int r = 1; r <= R; r++) {
                for (int c = 1; c <= C; c++) {
                    cin >> build[l][r][c];
                    if (build[l][r][c] == 'S') {
                        s.assign({ l,r,c,0 });
                    }
                    if (build[l][r][c] == 'E') {
                        e.assign({ l,r,c });
                    }
                }
            }
        }

        int answer = bfs();
        if (!answer) cout << "Trapped!\n";
        else cout << "Escaped in " << answer << " minute(s).\n";

    } while (1);
    return 0;
}