#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main() {
    fio();
    int N, M; cin >> N >> M;
    int P = 2 * N + 1;
    int answer = 0;
    string S; cin >> S;
    string pattern = "I";

    // make pattern
    for (int i = 0; i < N; i++) pattern += "OI";

    // KMP fail table
    vector<int> fail(P);
    for (int i = 1, j = 0; i < P; i++) {
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
        if (pattern[i] == pattern[j]) fail[i] = ++j;
    }

    // KMP matching
    for (int i = 0, p = 0; i < M; i++) {
        while (p > 0 && S[i] != pattern[p]) p = fail[p - 1];
        if (S[i] == pattern[p]) p++;
        if (p == P) { answer++; p = fail[p - 1]; }
    }

    cout << answer;

    return 0;
}
