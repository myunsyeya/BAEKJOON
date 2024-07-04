#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() ios_base::sync_with_stdio(0); cin.tie(0)

int D(const string& a, const string& b) {
    int dist = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) dist++;
    }
    return dist;
}

int main()
{
    fio();
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<string> mbti(N);
        for (string& m : mbti) cin >> m;
        int min = 20;
        
        if (N > 32) { cout << 0 << '\n'; continue; }

        for (int i = 0; i < N-2; i++) {
            for (int j = i+1; j < N-1; j++) {
                for (int k = j+1; k < N; k++) {
                    int now = D(mbti[i], mbti[j])+D(mbti[j], mbti[k])+D(mbti[i], mbti[k]);
                    if (min > now) min = now;
                }
            }
        }

        cout << min << '\n';
    }
    
    return 0;
}