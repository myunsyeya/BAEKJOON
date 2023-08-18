#include <iostream>

using namespace std;

inline int prefixsum(int num1, int num2) // 연속된 자연수의 수열이므로 등차수열이 보장된다.
{
	return (num1 + num2) * (num2 - num1 + 1) / 2;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, start, end, token = 0;
	start = end = 1;
	cin >> n;
	if (n == 1) token++;
	while (start < n)
	{
		if (prefixsum(start, end) >= n)
			start++;
		else 
			end++;
		if (prefixsum(start, end) == n)
			token++;
	}
	
	cout << token;

	return 0;
}