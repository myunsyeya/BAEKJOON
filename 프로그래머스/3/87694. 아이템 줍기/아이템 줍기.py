# 가장 짧은 거리 bfs
# 외곽선을 따라가는 코드를 짤 수 있는게 핵심이겠네
from collections import deque
def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    queue = deque([[(characterX, characterY), 0]])
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    # 외곽선을 캐치하기
    # 사각형의 길이는 모두 정수형, 모든 측정 길이는 단위 길이 1x1
    edge = []
    for rec_x1, rec_y1, rec_x2, rec_y2 in rectangle:
        for edge_x1 in range(rec_x2 - rec_x1):
            edge.append((rec_x1+edge_x1, rec_y1, rec_x1+edge_x1+1, rec_y1))
            edge.append((rec_x1+edge_x1, rec_y2, rec_x1+edge_x1+1, rec_y2))
        for edge_y1 in range(rec_y2 - rec_y1):
            edge.append((rec_x1, rec_y1+edge_y1, rec_x1, rec_y1+edge_y1+1))
            edge.append((rec_x2, rec_y1+edge_y1, rec_x2, rec_y1+edge_y1+1))
    outline = dict().fromkeys(edge, 1)
    # 포함관계인 edge 제거하기
    for rec_x1, rec_y1, rec_x2, rec_y2 in rectangle:
        for key in edge:
            edge_x1, edge_y1, edge_x2, edge_y2 = key
            if (rec_x1 < (edge_x1 + edge_x2)/2 and (edge_x1 + edge_x2)/2 < rec_x2):
                if rec_y1 < (edge_y1 + edge_y2)/2 and (edge_y1 + edge_y2)/2 < rec_y2:
                    outline[key] = 0
    outline = {key:value for key, value in outline.items() if value}
    # bfs
    while queue:
        cur, move = queue.popleft()
        cur_x, cur_y = cur
        if cur_x == itemX and cur_y == itemY:
            return move
        for x, y in zip(dx, dy):
            next_x = cur_x + x
            next_y = cur_y + y
            next_ = (next_x, next_y)
            if next_x < cur_x or next_y < cur_y:
                edge = (next_x, next_y, cur_x, cur_y)
            else:
                edge = (cur_x, cur_y, next_x, next_y)
            if edge in outline:
                if outline[edge]:
                    outline[edge] = 0
                    queue.append([next_, move+1])
    return answer