#include <iostream>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(int& a, int& b) const
	{
		return (abs(a) < abs(b)) ? 0 : (abs(b) < abs(a)) ? 1 : (a < b) ? 0 : (a == b)? 0 : 1;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int n, temp;
	priority_queue<int, vector<int>, compare> pq;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (!temp && pq.empty())
			cout << 0 << '\n';
		else if (!temp)
		{
			temp = pq.top();
			pq.pop();
			cout << temp << '\n';
		}
		else
			pq.push(temp);
	}
	return 0;
}