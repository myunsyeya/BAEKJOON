#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
* series_i = answer_i = 0 인덱스를 따로 설정.
* for(N만큼 반복) {
*	now(현재 sorted_series 데이터 값)
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
	vector<int> stack, series, sorted_series, answer;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		series.push_back(temp);
	}
	sorted_series = series;
	sort(sorted_series.begin(), sorted_series.end());
	
	series_i = 0;
	for (int i = 0; i < n; i++)
	{
		stack.push_back(sorted_series[i]);
		answer.push_back(1);
		while (!stack.empty() && stack.back() == series[series_i])
		{
			series_i++;
			stack.pop_back();
			answer.push_back(0);
		}
	}
	if (stack.empty())
		for (int i = 0; i < answer.size(); i++)
			cout << (answer[i] ? '+' : '-') << '\n';
	else
		cout << "NO";
	return 0;
}