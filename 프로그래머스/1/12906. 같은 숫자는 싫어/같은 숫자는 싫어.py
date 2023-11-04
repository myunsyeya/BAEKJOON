def solution(arr):
    answer = []
    for i in arr:
        if not len(answer):
            answer.append(i)
        if answer[-1] == i:
            pass
        else:
            answer.append(i)
    return answer