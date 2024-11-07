#include <iostream>
#include <vector>
#include <functional>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int delta[6] = {1, -1, 0, 0, 1, -1};

vector<vector<char>> board;
vector<vector<int>> visit;

void dfs(pair<int, int> cur, char color, function<bool(char, char)> judge)
{
    pair<int, int> next;
    for (int i = 0; i < 4; i++)
    {
        next.first = cur.first + delta[i];
        next.second = cur.second + delta[i + 2];
        char &nc = board[next.first][next.second];
        int &nv = visit[next.first][next.second];

        if (nv)
            continue;
        if (judge(nc, color))
        {
            nv = 1;
            dfs(next, color, judge);
        };
    }
}

int main()
{
    fio();

    int N;
    cin >> N;
    board = vector<vector<char>>(N + 2, vector<char>(N + 2));
    visit = vector<vector<int>>(N + 2, vector<int>(N + 2));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j];
        }
    }

    int n = 0, b = 0;
    /* normal */
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!visit[i][j])
            {
                visit[i][j] = 1;
                dfs({i, j}, board[i][j], [](char c, char n){ return c == n; });
                n++;
            }
        }
    }
    /* blindness */
    visit = vector<vector<int>>(N + 2, vector<int>(N + 2));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!visit[i][j]) {
                visit[i][j] = 1;
                dfs({i, j}, board[i][j], [](char c, char n) {
                    if ((c == 'R' || c == 'G') && (n == 'R' || n == 'G')) return true;
                    return c == n; 
                });
                b++;
            }
        }
    }

    cout << n << ' ' << b;

    return 0;
}