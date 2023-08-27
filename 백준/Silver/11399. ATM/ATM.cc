#include <iostream>
#include <iterator>

using namespace std;

inline void _swap(int& num1, int& num2)
{
	int	temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

void InsertionSort(int* (&arr), int size)
{
	int index;
	for (int i = 1; i < size; i++)
	{
		index = i;
		for (int j = i; j >= 0; j--)
		{
			if (arr[index] < arr[j])
			{
				_swap(arr[index], arr[j]);
				index--;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int		n;
	int	  sum;
	int*	p;
	
	cin >> n;
	p = new int[n];
	copy_n(istream_iterator<int>(cin), n, p);

	InsertionSort(p, n);

	for (int i = 1; i < n; i++)
		p[i] += p[i - 1];

	sum = 0;
	for (int i = 0; i < n; i++)
		sum += p[i];
	
	cout << sum;
	return 0;
}