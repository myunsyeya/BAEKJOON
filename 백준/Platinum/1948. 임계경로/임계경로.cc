#include <cstdio>
#include <string.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[10001], reverseGraph[10001], initialDelay[10001], initialReverseDelay[10001], visited[10001];
queue<int> q;
int route, delay[10001], indegree[10001];

int topologicalSort(int start, int end)
{
    int max_sum = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (delay[next] < delay[cur] + initialDelay[cur][i])
                delay[next] = delay[cur] + initialDelay[cur][i];
            indegree[next]--;
            if (!indegree[next])
                q.push(next);
        }
    }
    max_sum = delay[end];
    return max_sum;
}

void modifiedDfs(int cur, int max_sum)
{
    for (int i = 0; i < reverseGraph[cur].size(); i++) {
        int next = reverseGraph[cur][i];
        int chk = 0;
        if (delay[next] + initialReverseDelay[cur][i] == max_sum) {
            for (int i = 0; i < visited[cur].size(); i++)
                if (visited[cur][i] == next) {
                    chk = 1;
                    break;
                }
            if (!chk) {
                route++;
                visited[cur].push_back(next);
                modifiedDfs(next, max_sum - initialReverseDelay[cur][i]);
            }
            
        }
    }
}

int main(void)
{
    int n, m, start, end, sum;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, time;
        scanf(" %d %d %d", &a, &b, &time);
        indegree[b]++;
        graph[a].push_back(b);
        reverseGraph[b].push_back(a);
        initialDelay[a].push_back(time);
        initialReverseDelay[b].push_back(time);
    }
    scanf(" %d %d", &start, &end);
    sum = topologicalSort(start, end);
    modifiedDfs(end, sum);
    printf("%d\n%d\n", sum, route);
    return 0;
}