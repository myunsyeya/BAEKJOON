from collections import deque
def solution(priorities, location):
    answer = 0
    deq = deque(priorities)
    
    while deq:
        now = deq.popleft()
        if deq and now < max(list(deq)):
            deq.append(now)
            if not location:
                location = len(deq)
        else:
            answer += 1
            if not location:
                break
        location -= 1
    return answer