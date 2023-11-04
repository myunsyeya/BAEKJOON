from collections import deque
def solution(progresses, speeds):
    answer = []
    prog = deque(progresses)
    spee = deque(speeds)
    
    while prog:
        cnt = 0
        while prog and prog[0] >= 100:
            prog.popleft()
            spee.popleft()
            cnt += 1
        for i in range(len(prog)):
            prog[i] += spee[i]
        if cnt:
            answer.append(cnt)
        
    return answer