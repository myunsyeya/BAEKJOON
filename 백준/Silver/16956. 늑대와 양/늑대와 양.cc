#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

char matrix[510][510];
int d_x[4] = { 1, -1, 0, 0 };
int d_y[4] = { 0, 0, 1, -1 };

int main()
{
    fio();
    /*
     * 붙어있지만 않으면 무조건 가능
     * 그냥 S 근방에 전부 D 붙이고 D 자리에 W 있으면 불가
     */
    int R, C;
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cin >> matrix[i][j];
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            for (int k = 0; k < 4; k++) {
                if (matrix[i][j] == 'S') if (matrix[i+d_y[k]][j+d_x[k]] == 'W') { cout << 0; return 0; }
                if (matrix[i][j] == '.') matrix[i][j] = 'D';
            }
        }
    }
    cout << 1 << '\n';
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) cout << matrix[i][j];
        cout << '\n';
    }

    return 0;
}