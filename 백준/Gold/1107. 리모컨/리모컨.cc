#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define fio() do { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define MAX 1000000

bool button[10], cantry[MAX];

int main()
{
    int N, M;
	int min = MAX;
    int idx = MAX;
    char str_num[10];
	cin >> N >> M;
    while (M--) {
        int x;
        cin >> x;
        button[x] = true;
    }
    for (int i = 0; i < MAX; i++) {
        sprintf(str_num, "%d", i);
        for (int j = 0; j < strlen(str_num); j++)
            if (button[str_num[j] - '0']) { cantry[i] = true; break; }
    }

    for (int i = 0; i < MAX; i++) {
        if (!cantry[i]) 
        {
            if (N > i) { 
                if (N - i < min) { min = N - i; idx = i; } 
            } else if (i - N < min) { min = i - N; idx = i; }
        }
    }
    sprintf(str_num, "%d", idx);
    if ((100 - N >= 0) && (100 - N < min + strlen(str_num))) cout << 100 - N;
    else if ((N - 100 > 0) && (N - 100 < min + strlen(str_num))) cout << N - 100;
    else cout << min + strlen(str_num);
	return 0;
}