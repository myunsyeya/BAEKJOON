# 최소거리는 bfs 문제
# 효율성을 위해서는 -1 판별이 먼저 필요하겠네..
from collections import deque
def solution(maps):
    answer = 0
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    queue = deque()
    visited = [[False for j in i] for i in maps]
    visited[0][0] = True
    def bfs():
        queue.append([0,0,1])
        while queue:
            cur = queue.popleft()
            if visited[len(maps)-1][len(maps[0])-1]:
                if cur[0] == len(maps[0])-1 and cur[1] == len(maps)-1:
                    return cur[2]
                else:
                    continue
            for idx in range(4):
                next_x = cur[0] + dx[idx]
                next_y = cur[1] + dy[idx]
                if next_x >= 0 and next_x < len(maps[0]):
                    if next_y >= 0 and next_y < len(maps):
                        if not visited[next_y][next_x]:
                            if maps[next_y][next_x]:
                                visited[next_y][next_x] = True
                                queue.append([next_x, next_y, cur[2]+1])
        return -1
    answer = bfs()                        
    return answer