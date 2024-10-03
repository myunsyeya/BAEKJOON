#include <iostream>
#include <vector>

using namespace std;

#define fio() cin.tie(0), ios_base::sync_with_stdio(0)
/*
int strlcnt(string s, int n)
{
    int cnt = 0;
    for (int i = n; s[i] >= 'a' && s[i] <= 'z'; i++) cnt++;
    return cnt;
}
*/
int main()
{
    fio();

    int N; cin >> N;
    string S; cin >> S;
    int D, M; cin >> D >> M;
    int energy, h, y, u;
    energy = h = y = u = 0;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'H' || S[i] == 'Y' || S[i] == 'U') {
            if (S[i] == 'H') h++;
            else if (S[i] == 'Y') y++;
            else if (S[i] == 'U') u++;
            energy += min(M+D, cnt*D);
            cnt = 0;
        }
        else cnt++;
    }
    energy += min(M+D, cnt*D);
    if(!energy) cout << "Nalmeok" << '\n';
    else cout << energy << '\n';
    if(!min(h,min(y,u))) cout << "I love HanYang University";
    else cout << min(h,min(y,u));

    return 0;
}