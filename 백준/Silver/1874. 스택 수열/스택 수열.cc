#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
* !핵심은 두 가지!
* !1부터 N까지 모든 수는 중복 없는 정수!, 따라서 오름차순으로 넣으면 1부터 N까지 삽입!
* !stack의 top이 수열의 값보다 크면, 원하는 수열을 만들 수 없으므로(여러 번 pop해야 하므로) 불가!
* series_i = answer_i = 0 인덱스를 따로 설정.
* for(N만큼 반복) {
*	now(현재 데이터 값)
*	now를 stack에 push
*	series와 stack.top이 같을 때 동안
*	sries_i 증가
*	(push와 pop 동작마다 answer에 1 0으로 기록한다.)
*	stack은 pop
* }
* for 이후 stack이 비어있지 않으면 불가
* 비어있다면 answer 출력
*/

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	
	int n, temp, series_i;
	vector<int> stack, series, answer;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		series.push_back(temp);
	}
	
	series_i = 0;
	for (int i = 1; i <= n; i++)
	{
		stack.push_back(i);
		answer.push_back(1);
		while (!stack.empty() && stack.back() == series[series_i])
		{
			series_i++;
			stack.pop_back();
			answer.push_back(0);
		}
		if (!stack.empty() && stack.back() > series[series_i])
			break;
	}
	if (stack.empty())
		for (int i = 0; i < answer.size(); i++)
			cout << (answer[i] ? '+' : '-') << '\n';
	else
		cout << "NO";
	return 0;
}