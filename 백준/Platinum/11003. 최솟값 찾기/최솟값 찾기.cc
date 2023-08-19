#include <iostream>
#include <vector>
#include <queue>
#include <iterator>

using namespace std;

int n, l, a[5000001];
vector<int> d;
struct MinimumNumber
{
	int number;
	int index;
	MinimumNumber(int num, int idx) : number(num), index(idx) {}
	bool operator<(const MinimumNumber s) const
	{
		return this->number > s.number;
	}
};

void SlidingWindow()
{
	int start, i = 1;
	priority_queue<MinimumNumber> pq;
	while (i <= n)
	{
		start = (i - l + 1 < 1)? 1: i - l + 1;
		pq.push({ a[i], i });
		while (!pq.empty())
		{
			if (pq.top().index < start)
				pq.pop();
			else
			{
				d.push_back(pq.top().number);
				break;
			}
		}
		i++;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	SlidingWindow();
	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	return 0;
}