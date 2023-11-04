from collections import deque
def solution(bridge_length, weight, truck_weights):
    answer = 0
    idle = deque(truck_weights)
    bridge = deque([0]*bridge_length)
    sum_weight = 0
    
    while bridge:
        sum_weight -= bridge.popleft()
        if idle:
            if sum_weight + idle[0] <= weight:
                sum_weight += idle[0]
                bridge.append(idle.popleft())
            else:
                bridge.append(0)
        answer += 1
    return answer