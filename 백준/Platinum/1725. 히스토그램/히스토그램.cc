#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

int histogram[100000];

#define MIN(x, y) (x < y)? x: y

ll solve(int start, int end)
{
	// stop point
	if (start > end)
		return 0;
	int mid = start + (end - start) / 2;
	int left = mid - 1, right = mid + 1;
	int anchor = histogram[mid];
	ll count = 2;
	ll area, conquerMax, leftDivideMax, rightDivideMax;
	// divide
	leftDivideMax = solve(start, left);
	rightDivideMax = solve(right, end);
	// conquer
	conquerMax = anchor;
	while (left >= start && right <= end) {
		int largest = (histogram[left] > histogram[right]) ? histogram[left--] : histogram[right++];
		anchor = MIN(anchor, largest);
		area = (count++) * anchor;
		if (conquerMax < area)
			conquerMax = area;
	}
	while (left >= start) {
		int le = histogram[left--];
		anchor = MIN(anchor, le);
		area = (count++) * anchor;
		if (conquerMax < area)
			conquerMax = area;
	}
	while (right <= end) {
		int ri = histogram[right++];
		anchor = MIN(anchor, ri);
		area = (count++) * anchor;
		if (conquerMax < area)
			conquerMax = area;
	}
	conquerMax = conquerMax > leftDivideMax ? conquerMax : leftDivideMax;
	conquerMax = conquerMax > rightDivideMax ? conquerMax : rightDivideMax;
	return conquerMax;
}

int main(void)
{
	int N;
	do {
		memset(histogram, 0, sizeof(histogram));
		scanf(" %d", &N);
		for (int i = 0; i < N; i++)
			scanf(" %d", &histogram[i]);
		if (N)
			printf("%lld\n", solve(0, N - 1));
        break;
	} while (N);
	return 0;
}