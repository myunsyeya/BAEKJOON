#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

int main()
{
    fio();
    int N, M, skip, temp;
    cin >> N >> M;
    skip = N - M;
    temp = 1;
    // n P m
    vector<int> round;
    for (int i = 1; i <= N; i++) round.push_back(i);
    for (int i = skip-1; i > 0; i--) skip *= i;
    do {
        if (N-M) {
            if (--temp) continue;
            if (!temp) temp = skip;
        }
        bool check = true;
        for (int i = 0; i < M-1; i++) if (round[i] > round[i+1]) check = false;
        if (!check) continue;
        for (int i = 0; i < M; i++) cout << round[i] << ' ';
        cout << '\n';
    } while(next_permutation(round.begin(), round.end()));
    return 0;
}