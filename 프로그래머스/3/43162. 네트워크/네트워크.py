answer = 0
visited = []
def solution(n, computers):
    global answer
    global visited
    visited = [False] * n
    def dfs(v):
        global visited
        visited[v] = True
        for idx, vertex in enumerate(computers[v]):
            if not visited[idx] and vertex:
                dfs(idx)
    
    while False in visited:
        dfs(visited.index(False))
        answer += 1
    return answer