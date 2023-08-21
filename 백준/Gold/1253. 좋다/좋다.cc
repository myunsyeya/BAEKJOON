#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, start, end, count = 0;
	int series[2001];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> series[i];
	sort(series, series + n);
	for (int i = 0; i < n; i++)
	{
		start = 0; end = n - 1;
		while (start < end)
		{
			if (series[start] + series[end] == series[i])
			{
				if (start != i && end != i)
				{
					count++;
					break;
				}
				else if (start == i) start++;
				else if (end == i) end--;
			}
			else if (series[start] + series[end] < series[i]) start++;
			else end--;
		}
	}

	cout << count;
	return 0;
}