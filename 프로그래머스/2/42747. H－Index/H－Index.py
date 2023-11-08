def solution(citations):
    answer = 0
    citations.sort(reverse=True)
    h = citations[0]
    for idx in range(len(citations)):
        if not h > idx:
            break
        h = citations[idx] if idx < citations[idx] else idx
    else:
        h = len(citations) if h > len(citations) else h
    return h