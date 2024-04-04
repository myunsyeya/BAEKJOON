#include <iostream>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int N, ans;
int flag_a[15];
int flag_b[30];
int flag_c[30];
int pos[15];

void set(int i)
{
    for (int j = 0; j < N; j++) {
        if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + N - 1]) {
            pos[i] = j;
            if (i == N - 1) ans++;
            else {
                flag_a[j] = flag_b[i + j] = flag_c[i - j + N - 1] = 1;
                set(i+1);
                flag_a[j] = flag_b[i + j] = flag_c[i - j + N - 1] = 0;
            }
        }
    }
}

int main()
{
    fio();
    cin >> N;
    set(0);
    cout << ans;
    return 0;
}