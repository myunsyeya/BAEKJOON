def solution(sizes):
    answer = 0
    lis = list(map(lambda x: [x[0], x[1]] if x[0] < x[1] else [x[1], x[0]], sizes))
    answer = max(list(map(lambda x: x[0], lis))) * max(list(map(lambda x: x[1], lis)))
    return answer