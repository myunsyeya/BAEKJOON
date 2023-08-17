#include <iostream>

using namespace std;

int prefixsum[100000];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, m, i, j;
	cin >> n >> m >> prefixsum[0];
	for (int i = 1; i < n; i++)
	{
		cin >> prefixsum[i];
		prefixsum[i] += prefixsum[i - 1];
	}
	for (int line = 0; line < m; line++)
	{
		cin >> i >> j;
		cout << prefixsum[j - 1] - prefixsum[i - 2] << '\n';
	}

	return 0;
}