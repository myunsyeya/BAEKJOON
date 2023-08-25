#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

/* 고찰
* 똑같이 N^2으로 순회하면 시간초과! (25 x 10^5 x 10^5 -> 2500억번.. 2500초)
* swap에서 특징을 발견할 수 있지 않을까?
* if (A[j] > A[j+1]) swap이라면 안쪽 루프에서 이동한 A[j+1]은 항상 1번만 이동
* 변화가 없을 때까지 제 자리를 찾지 못한 데이터는 매번 왼쪽으로 이동할 것
* 즉, 왼쪽으로 제일 많이 이동한 데이터의 이동횟수가 곧 안쪽 루프의 반복 횟수!
*/
/* 의사코드
* N(데이터의 크기), I(현재 인덱스), MAXIndex(왼쪽으로 최대 이동한 거리)
* Series(데이터, 처음 인덱스를 가진 구조체 배열)
* 
* Series 정렬
* for N:
*	temp = Series[I].Index - I + 1	// 왼쪽으로 이동했다면 양수
*	if(MAXIndex < temp):
*		MAXIndex = temp
*/
struct Pair // 원래라면.. utility 헤더의 pair와 겹치므로 지양하는 것이 원칙
{
	int data;
	int index;
	bool operator<(const Pair& target) const
	{
		return data < target.data;
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	
	int n, maxindex = INT32_MIN;
	Pair* series;
	cin >> n;
	series = new Pair[n + 1];
	
	for (int temp, i = 1; i <= n; i++)
	{
		cin >> temp;
		series[i].data = temp;
		series[i].index = i;
	}
	stable_sort(series + 1, series + n + 1);
	for (int temp, i = 1; i <= n; i++)
	{
		temp = series[i].index - i + 1;
		if (maxindex < temp) maxindex = temp;
	}

	cout << maxindex;
	return 0;
}