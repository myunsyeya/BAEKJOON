#include <iostream>

using namespace std;

int prefixsum[1025][1025]; // sum의 방향은 해당 행을 기준으로.

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, m, x1, y1, x2, y2;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			cin >> prefixsum[i][j];
			prefixsum[i][j] += prefixsum[i][j - 1];
		}
	for (int i = 0; i < m; i++)
	{
		int sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int row = x1; row <= x2; row++)
		{
			sum += prefixsum[row][y2] - prefixsum[row][y1 - 1];
		}
		cout << sum << '\n';
	}
	
	return 0;
}