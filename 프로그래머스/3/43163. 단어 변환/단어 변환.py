# 가장 짧은 변환 과정 => bfs
from collections import deque
def solution(begin, target, words):
    answer = 0
    queue = deque([[begin,0]])
    words = {i:0 for i in words}
    n = range(len(target))
    
    # 미도달 경우 확인
    if not target in words:
        return 0
    while queue:
        cur, move = queue.popleft()
        if cur == target:
            answer = move
            break
        for word in words:
            if words[word]:
                continue
            diff = 0
            for idx in n:
                if cur[idx] != word[idx]:
                    diff += 1
            if diff == 1:
                words[word] += 1
                queue.append([word, move+1])
    return answer