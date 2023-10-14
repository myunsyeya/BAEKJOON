# 정수의 닫힌 구간 집합 routes에 대하여 
# overap하는 routes의 원소들의 intersect(r_1, r_2, ...)를 I라고 하자.
# 그러면 answer는 I의 개수 + disjoint한 routes의 원소 개수
# 굳이 I를 생성하지 않고,
# routes를 overlap하는 원소들과 disjoint한 원소로 나누어 풀어도 되겠다.
# 구간이 겹치는 친구들을 어떻게 추려낼 수 있지?
def solution(routes):
    answer = 0
    routes = list(map(sorted, routes))
    routes.sort()
    while len(routes) > 1:
        # disjoint
        if routes[0][1] < routes[1][0]:
            routes.pop(0)
            answer+= 1
        # overlap, minimum join
        else:
            routes[1][1] = min(routes[0][1], routes[1][1])
            routes.pop(0)
    answer += 1
    return answer