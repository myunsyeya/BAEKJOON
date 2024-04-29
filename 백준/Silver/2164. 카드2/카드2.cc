#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, temp;
	queue<int> q;

	cin >> n;
	for (int i = 1; i <= n; i++)
		q.push(i);

	while (q.size() != 1)
	{
		q.pop();
		temp = q.front();
		q.pop();
		q.push(temp);
	}

	cout << q.front() << '\n';
	return 0;
}