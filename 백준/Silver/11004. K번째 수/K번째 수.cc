#include <iostream>
#include <iterator>

using namespace std;

inline void _swap(int& num1, int& num2)
{
	int		temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

inline void SortTriad(int arr[], int a, int b, int c)
{
	if (arr[b] < arr[a]) _swap(arr[b], arr[a]);
	if (arr[c] < arr[b]) _swap(arr[c], arr[b]);
	if (arr[b] < arr[a]) _swap(arr[b], arr[a]);
}
void InsertionSort(int arr[], int left, int right)
{
	int		index;
	for (int i = left + 1; i < right + 1; i++)
	{
		index = i;
		for (int j = i; j >= left; j--)
		{
			if (arr[index] < arr[j])
			{
				_swap(arr[index], arr[j]);
				index--;
			}
		}
	}
}
void QuickSort(int arr[], int left, int right)
{
	if (right - left < 9)
	{
		/* 퀵정렬의 구조 상 매우 적은 요소의 정렬은 연산이 느립니다. */
		InsertionSort(arr, left, right);
		return;
	}
	int		pivot;
	int		pleft;
	int		pright;

	pleft = left;
	pright = right;
	SortTriad(arr, left, (left + right) / 2, right);
	pivot = arr[(left + right) / 2];
	_swap(arr[(left + right) / 2], arr[right - 1]);
	pleft	+= 1;
	pright	-= 2;
	do
	{
		while (arr[pleft] < pivot) pleft++;
		while (arr[pright] > pivot) pright--;
		if (pleft <= pright)
		{
			_swap(arr[pleft], arr[pright]);
			pleft++;
			pright--;
		}
	} while (pleft <= pright);
	if (pright - left > right - pleft)
	{
		_swap(left, pleft);
		_swap(right, pright);
	}
	if (left < pright) QuickSort(arr, left, pright);
	if (pleft < right) QuickSort(arr, pleft, right);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int		n;
	int		k;
	int*	a;
	
	cin >> n >> k;
	a = new int[n];
	copy_n(istream_iterator<int>(cin), n, a);

	QuickSort(a, 0, n - 1);

	cout << a[k - 1];
	delete[] a;
	return 0;
}