# 총 경우의 수는 5 product i(중복순열)
# 어느정도 가지치기 정도는 가능하지 않을까?
# 5pi1 + 5pi2 + 5pi3 + 5pi4 + 5pi5 = 3905 => 3905 // 5 = 781
# 하지만 일단 멍청하게 풀기..
from itertools import product
from itertools import chain
def solution(word):
    answer = 0
    return sorted(list(map(lambda x: ''.join(x), (chain(*list(product("AEIOU", repeat=i) for i in range(1,6))))))).index(word)+1