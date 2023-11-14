# 8! = 40320이므로 순열로 매겨봐도 된다.
from itertools import permutations
def solution(k, dungeons):
    answer = -1
    for dungeon_list in list(permutations(dungeons,len(dungeons))):
        answer = max(answer, adventure(k, dungeon_list))
    return answer

def adventure(k, dungeons):
    exp = 0
    for threshold, fatigue in dungeons:
        if k < threshold:
            return exp
        k -= fatigue
        exp += 1
    return exp