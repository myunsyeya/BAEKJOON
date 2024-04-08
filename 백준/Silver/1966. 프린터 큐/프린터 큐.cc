#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int main(void)
{
    int testCase;
    int jobNumber;
    int jobPosition;
    int count;
    int priority;
    int jobNow;
    bool temp = false;
    queue<int> q;
    scanf("%d", &testCase);
    while (testCase--) {
        scanf("%d %d", &jobNumber, &jobPosition);
        count = 0;
        for (int i = 0; i < jobNumber; i++) {
            scanf("%d", &priority);
            q.push(priority);
        }
        while (jobNumber) {
            temp = false;
            jobNow = q.front();
            q.pop();
            q.push(jobNow);
            /* 꺼내려는 숫자의 priority가 다른 요소보다 높은지 확인 */
            for (int i = 0; i < jobNumber - 1; i++) {
                priority = q.front();
                q.pop();
                q.push(priority);
                if (jobNow < priority)
                    temp = true;
            }
            jobNow = q.front();
            q.pop();
            /* pop이 성공적으로 진행되면, jobPosition이 한 칸 당겨진다 */
            jobPosition--;
            /* 높지 않다면, 맨 뒤에 push한다 */
            if (temp) {
                q.push(jobNow);
                /* 목적 문서가 뒤로 가면 jobPosition을 재설정한다 */
                if (jobPosition == -1) {
                    jobPosition = jobNumber - 1;
                }
            }
            else {
                /* 목적 문서가 반환되면 break */
                if (jobPosition == -1) {
                    count++;
                    while (!q.empty())
                        q.pop();
                    break;
                }
                jobNumber--;
                count++;
                
            }
        }
        printf("%d\n", count);
    }
    return 0;
}