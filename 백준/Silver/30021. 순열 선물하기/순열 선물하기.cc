#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();
    /*
     * 1부터 n까지의 합은 (n)*(n+1)/2
     * n = 2를 제외한 모든 수는 합성수이므로
     * n >= 3인 모든 n에 대하여 1 3 2 4 5 .. 순으로 출력하면 모두 정답이다.
     */
    int N;
    cin >> N;
    if (N == 1) cout << "YES\n" << 1;
    else if (N == 2) cout << "NO";
    else {
        cout << "YES\n" << "1 3 2 ";
        for (int i = 4; i <= N; i++) cout << i << ' ';
    }

    return 0;
}