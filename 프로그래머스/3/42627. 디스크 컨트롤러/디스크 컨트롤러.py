# SJF나 HRN이 있겠지만, 단순한 걸 사용했겠지.. pick SJF
import heapq
def solution(jobs):
    answer = 0
    n = len(jobs)
    now = 0
    start = -1
    pq = []
    
    # 일단, 요청시간 정렬
    jobs.sort()
    while jobs:
        # 현 시점에서 가능한 job 중 SJF 채택
        for job in jobs:
            if start < job[0] <= now:
                # Shortest Job First
                heapq.heappush(pq, [job[1], job[0]])
        if pq:
            # 작업 시작 시간 갱신
            start = now
            job = heapq.heappop(pq)
            now += job[0]
            answer += now - job[1]
            jobs.remove([job[1], job[0]])
        else:
            # 적당한 작업이 없으면, 시간이 흐르도록.
            now += 1
    return answer // n