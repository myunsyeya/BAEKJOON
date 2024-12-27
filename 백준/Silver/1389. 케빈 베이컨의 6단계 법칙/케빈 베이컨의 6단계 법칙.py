def floyd_warshall(graph):
    n = len(graph)
    dist = graph[:]
    
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

inf = float('inf')
N, M, *lis = map(int, open(0).read().split())
graph = [[inf]*N for _ in range(N)]
answer = 0

for i in range(N): graph[i][i] = 0
for i in range(M):
    u, v = lis[i*2]-1, lis[i*2+1]-1
    graph[u][v] = 1
    graph[v][u] = 1
graph = floyd_warshall(graph)
for i in range(N):
    if sum(graph[answer]) > sum(graph[i]): answer = i
print(answer+1)