def merge_sort(A, p, r, K): # A[p..r]을 오름차순 정렬한다.
    if p < r:
        q = (p + r) // 2         # q는 p, r의 중간 지점
        result = merge_sort(A, p, q, K)      # 전반부 정렬
        if result is not None:
            return result
        result = merge_sort(A, q + 1, r, K)  # 후반부 정렬
        if result is not None:
            return result
        result = merge(A, p, q, r, K)        # 병합
        if result is not None:
            return result
    return None

# A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.# A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
def merge(A, p, q, r, K):
    i, j, t = p, q+1, 0
    tmp = [0] * (r - p + 1)
    global count
    while i <= q and j <= r:
        if A[i] <= A[j]:
            tmp[t] = A[i]
            t += 1
            i += 1
        else:
            tmp[t] = A[j]
            t += 1
            j += 1
    while i <= q:
        tmp[t] = A[i]
        t += 1
        i += 1
    while j <= r:
        tmp[t] = A[j]
        t += 1
        j += 1
    for i in range(p, r + 1):
        A[i] = tmp[i - p]
        count += 1
        if count == K:
            return A[i]
    return None

N, K, *A = map(int, open(0).read().split())
count = 0
result = merge_sort(A, 0, N - 1, K)
print(result if result is not None else -1)