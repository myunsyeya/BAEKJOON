# 총 경우의 수는 5 product i(중복순열)
# 어느정도 가지치기 정도는 가능하지 않을까?
# 5pi1 + 5pi2 + 5pi3 + 5pi4 + 5pi5 = 3905 => 3905 // 5 = 781
# 역으로 생각하면 5, 5*5, 5*5 ...로 수학식 전개가 가능할 것.
# 하지만 완전탐색이므로 일단 멍청하게 풀기..
from itertools import product
from itertools import chain
def solution(word):
    return sorted(list(map(lambda x: ''.join(x), (chain(*list(product("AEIOU", repeat=i+1) for i in range(5))))))).index(word)+1