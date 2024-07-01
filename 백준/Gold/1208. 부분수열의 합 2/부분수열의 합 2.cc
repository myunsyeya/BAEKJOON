#include <iostream>
#include <algorithm>
#include <vector>

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
#define __ABS(x) (((x) < 0) ? -(x) : (x))

using namespace std;

typedef long long ll;

vector<ll> A, B;
ll s;
ll temp[40];

void input()
{
    int n, a, b;
    cin >> n >> s;
    a = n/2; b = n - a;
    ll na = 1 << a;
    ll nb = 1 << b;
    for (int i = 0; i < a; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < na; i++) {
        ll sum = 0;
        for (int j = 0; j < a; j++)
            if (i&(1<<j)) sum += temp[j];
        A.push_back(sum);
    }
    for (int i = 0; i < b; i++) {
        cin >> temp[i];
    }
    for (int i = 0; i < nb; i++) {
        ll sum = 0;
        for (int j = 0; j < b; j++)
            if (i&(1<<j)) sum += temp[j];
        B.push_back(sum);
    }
    
}

int main()
{
    fio();
    ll answer = 0;
    input();

    sort(B.begin(), B.end());

    for (ll a : A) {
        ll target = s - a;
        auto ub = upper_bound(B.begin(), B.end(), target);
        auto lb = lower_bound(B.begin(), B.end(), target);
        if ((lb != B.end()) && (*lb == target))
            answer += ub - lb;
    }
    if (!s) answer--;   // 둘 다 선택치 않는 경우는 크기가 양수가 아니다.
    cout << answer;
    return 0;
}