from collections import Counter
def solution(nums):
    answer = 0
    answer = len(list(Counter(nums)))
    return answer if answer < len(nums)/2 else len(nums)/2