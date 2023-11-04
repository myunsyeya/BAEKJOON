import heapq
def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    mix = heapq.heappop(scoville)
    while mix < K: 
        mix += 2 * heapq.heappop(scoville)
        mix = heapq.heappushpop(scoville, mix)
        answer += 1
        # if this system is inconsistent,
        if len(scoville) == 1 and scoville[0] < K:
            return -1
    return answer