from heapq import heappop, heappush

def solve(N, K):
    # Priority Queue에서 (min(LS, RS), max(LS, RS), -start, end)의 형태로 관리
    # 우선 min(LS, RS)가 큰 순, max(LS, RS)가 큰 순, 그다음 왼쪽에 가까운 순(-start가 큰 순)
    pq = []
    heappush(pq, (0, 0, 0, N-1))
    for _ in range(K):
        _, _, s, e = heappop(pq)
        s = -s
        mid = (s+e) >> 1
        LS = mid - s
        RS = e - mid
        if mid - 1 >= s:
            heappush(pq, (-(mid-s-1), -(mid-s-1), -s, mid-1))
        if mid + 1 <= e:
            heappush(pq, (-(e-mid-1), -(e-mid-1), -(mid+1), e))
    return max(LS, RS), min(LS, RS)

T = int(input())
for t in range(1, T + 1):
    N, K = map(int, input().split())
    max_, min_ = solve(N, K)
    print(f"Case #{t}: {max_} {min_}")