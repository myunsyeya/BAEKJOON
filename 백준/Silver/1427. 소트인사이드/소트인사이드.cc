#include <iostream>

using namespace std;

inline void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int maxindex;
	string number;
	cin >> number;

	for (int i = 0; number[i]; i++) // number.size() 가능
	{
		maxindex = i;
		for (int j = i; number[j]; j++)
			if (number[maxindex] < number[j])
				maxindex = j;
		swap(number[i], number[maxindex]);
	}
	cout << number;
	return 0;
}