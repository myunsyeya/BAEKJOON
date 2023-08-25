#include <iostream>
#include <iterator>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	
	int n;
	int* arr;
	cin >> n;
	arr = new int[n];
	copy_n(istream_iterator<int>(cin), n, arr);

	// 향상된 버블정렬
	for(int cnt = 0, i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				cnt++;
			}
		}
		if (!cnt) break;
	}

	copy(arr, arr + n, ostream_iterator<int>(cout, "\n"));
	return 0;
}