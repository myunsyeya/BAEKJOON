#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int n, temp;
	queue<int> myqueue;

	cin >> n;
	for (int i = 1; i <= n; i++)
		myqueue.push(i);

	while (myqueue.size() != 1)
	{
		myqueue.pop();
		temp = myqueue.front();
		myqueue.pop();
		myqueue.push(temp);
	}

	cout << myqueue.front() << endl;
	return 0;
}