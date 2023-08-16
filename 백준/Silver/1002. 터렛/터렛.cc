#include <iostream>
#include <cmath>

using namespace std;

inline double DistanceFormular(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

/*
* r1 = r2, d = 0, -> infinity
* |r1 - r2| < d < r1 + r2 -> two point approach
* r1 + r2 = d, |r1 - r2| = d -> one point approach
* r1 + r2 < d, |r1 - r2| > d, d = 0 -> not approach
*/
int RelationshipOfTwoCircles(int r1, int r2, double d)
{
	if (r1 == r2 && !d)
		return -1;
	if (abs(r1 - r2) < d && d < r1 + r2)
		return 2;
	if (abs(r1 - r2) == d || d == r1 + r2)
		return 1;
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test_case;
	cin >> test_case;
	
	for (int i = 0; i < test_case; i++)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << RelationshipOfTwoCircles(r1, r2, DistanceFormular(x1, y1, x2, y2)) << endl;
	}

	return 0;
}