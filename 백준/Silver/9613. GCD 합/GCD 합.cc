#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

typedef long long ll;

int __gcd(int a, int b) {
	if (!b) return a;
	return __gcd(b, a % b);
}

int main()
{
	fio();
	int t;
	cin >> t;
	while (t--) {
		int n;
        ll sum;
		cin >> n;
		vector<bool> comb(n, false);
		vector<int> num(n), gcd;
		comb[0] = comb[1] = true;
		for (int& x : num) {
			cin >> x;
		}
		sum = 0;

		do {
			int a, b;
			for (size_t i = 0; i < comb.size(); i++)
				if (comb[i]) gcd.push_back(i);
			a = num[gcd.back()]; gcd.pop_back();
			b = num[gcd.back()]; gcd.pop_back();
			sum += (a < b) ? __gcd(b, a) : __gcd(a, b);
		} while (prev_permutation(comb.begin(), comb.end()));
		cout << sum << '\n';
	}

	return 0;
}