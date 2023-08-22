#include <iostream>
#include <iterator>
#include <vector>
#include <stack>

using namespace std;
/* 고찰
* 10^6 자료크기 N에 대하여 O(NlogN) 이상은 시간초과
* 가능한 한 O(N): 자료를 한 번만 순회할 수 있는 코드로 작성.
* 오큰수 특성 상 자기보다 큰 값이 나올 때까지 유휴 상태
* [5, 2, 7]에서 5, 2는 7을 만나기 전까지 값의 지정이 불가함.
* 쌓아놓고 하나씩 꺼내어 비교하는(stack) 자료형이 적합.
* 그러나 값으로 비교하여 출력하면 부분적 역순으로 출력될 것. [5, 2] -> 2(7), 5(7)
* 따라서 자료의 색인을 스택에 쌓고 정답 배열을 만들어서 정답[색인] = 오큰수가 되도록 저장하면
* 정답 배열을 순회하는 것으로 정방향 출력이 가능!
*/
/* 의사코드
* N(수열의 크기), I(현재 색인)
* Series(수열), NGEIndex(오큰수 배열(크기 N))
* Stack(NGEIndex에 저장되기 전의 색인)
* for N: {
*	while Stack이 빌 때까지: {
*		if Series[Stack.top] < Series[I]: {
*			NGEIndex[Stack.top] = Series[I]
*			Stack.pop
*		}
*		else break;
*	}
*	push I
* }
* while Stack이 빌 때까지: {
*	NGEIndex[Stack.top] = -1
*	Stack.pop
* }
*/
int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	int n;
	vector<int> series, ngeindex;
	stack<int> idle;

	cin >> n;
	series = ngeindex = vector<int>(n, 0);
	copy_n(istream_iterator<int, char>(cin), n, series.begin());

	for (int index = 0; index < n; index++)
	{
		while (!idle.empty() && series[idle.top()] < series[index])
		{
			ngeindex[idle.top()] = series[index];
			idle.pop();
		}
		idle.push(index);
	}
	while (!idle.empty())
	{
		ngeindex[idle.top()] = -1;
		idle.pop();
	}
	copy(ngeindex.begin(), ngeindex.end(), ostream_iterator<int>(cout, " "));
	return 0;
}