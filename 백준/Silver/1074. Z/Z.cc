#include <cstdio>
#include <cmath>
using namespace std;

int R, C, cnt;

void solve(int N, int r, int c)
{
	int tkn = 0;
	int next = (int)pow(2, N - 1);
	if (N > 1) 
	{
		if (r + next > R) 
		{
			if(c + next > C)
				solve(N - 1, r, c);
			else 
			{
				cnt += next * next;
				solve(N - 1, r, c + next);
			}
		}
		else 
		{
			if (c + next > C) 
			{
				cnt += 2 * next * next;
				solve(N - 1, r + next, c);
			}
			else 
			{
				cnt += 3 * next * next;
				solve(N - 1, r + next, c + next);
			}
		}
	}
	else
		for (int i = 0; i < 2 && !tkn; i++)
			for (int j = 0; j < 2 && !tkn; j++, cnt++)
				if (r + i == R && c + j == C)
					tkn = 1;
}

int main(void)
{
	int N;
	scanf(" %d %d %d", &N, &R, &C);
	solve(N, 0, 0);
	printf("%d\n", cnt - 1);
	return 0;
}