#include <iostream>

using namespace std;

int number[1000001];
long long remainders[1001];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, m;
	long long count = 0;
	cin >> n >> m >> number[0];
	number[0] %= m;
	remainders[number[0]]++;
	if (!number[0])
		count++;
	for (int i = 1; i < n; i++)
	{
		cin >> number[i];
		number[i] = (number[i] % m + number[i - 1]) % m;
		remainders[number[i]]++;
		if (!number[i])
			count++;
	}
	for (int i = 0; i < m; i++)
		if (remainders[i])
			count += remainders[i] * (remainders[i] - 1) / 2;
	cout << count;
	return 0;
}