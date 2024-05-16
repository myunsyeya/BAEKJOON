#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

vector<int> answer;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int map[30][30];
int visited[30][30];

int main()
{
    fio();
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        string bits; cin >> bits;
        for (int j = 1; j <= n; j++) map[i][j] = bits[j-1] - '0'; 
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!map[i][j] || visited[i][j]) continue;
            /* bfs */
            int cnt = 1;
            queue<tuple<int,int>> q;
            q.push(make_tuple(i, j));
            visited[i][j] = 1;

            while (!q.empty()) {
                int cr, cc;
                tie(cr, cc) = q.front(); q.pop();
                
                for (int i = 0; i < 4; i++) {
                    int nr = cr + dr[i];
                    int nc = cc + dc[i];
                    if (!map[nr][nc] || visited[nr][nc]) continue;
                    visited[nr][nc] = 1;
                    q.push({nr, nc});
                    cnt++;
                }
            }
            answer.push_back(cnt);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int i : answer) cout << i << '\n';
    return 0;
}