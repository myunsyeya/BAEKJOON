#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)

int main()
{
    fio();

    int N; cin >> N;
    string s; cin >> s;

    int min_gap = N;
    vector<int> cow;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') cow.push_back(i);
    }
    for (int i = 1; i < cow.size(); i++) {
        min_gap = min(min_gap, cow[i]-cow[i-1]);
    }

    /* 0...0 */
    if (cow.empty()) { cout << N-1; return 0; }
    
    int le = 1;
    int ri = N;
    int answer = 0;
    while (le <= ri) {
        int cows = 0;
        int mid = (le+ri) >> 1;
        /* left padding */
        cows += (cow.front())/mid;
        /* inner gap */
        for (int i = 1; i < cow.size(); i++) {
            int p = (cow[i]-cow[i-1])/mid-1;
            if (p > 0) cows += p;
        }
        /* right padding */
        cows += (N-cow.back())/mid;

        if (cows >= 2) { le = mid+1; answer = mid; }
        else ri = mid-1;
    }
    answer = min(answer, min_gap);

    cout << answer;

    return 0;
}