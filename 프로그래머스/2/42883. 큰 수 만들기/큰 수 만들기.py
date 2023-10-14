# 스택을 활용한 풀이
def solution(number, k):
    answer = ''
    stack = []
    for num in number:
        while stack and k and stack[-1] < num:
            stack.pop()
            k -= 1
        stack.append(num)
    while stack and k:
        stack.pop()
        k -= 1
    answer = ''.join(map(str, stack))
    return answer

"""
# 진짜 반례를 빼곡히 채워도 허점을 못 찾겠음. 같이 검토해보면 좋을텐데..
# min heap 사용. 더 큰 수를 만나면 pop하기. k만큼 pop하면 종료.
from heapq import heappush, heappop
def solution(number, k):
    answer = ''
    number = list(map(int,list(number)))
    mil = []
    remove_index = []
    # 작은 거 추리기
    for i in range(len(number)):
        if not k:
            break
        if not mil:
            heappush(mil, (number[i],i))
            continue
        if mil[0][0] < number[i]:
            remove_index.append(heappop(mil)[1])
            k -= 1
        heappush(mil,(number[i],i))
    for i in range(k):
        remove_index.append(heappop(mil)[1])
    remove_index.sort()
    for i in remove_index[::-1]:
        number.pop(i)
    answer = ''.join(map(str,number))
    return answer
"""