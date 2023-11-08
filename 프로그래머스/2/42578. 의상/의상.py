from collections import Counter
def solution(clothes):
    answer = 1
    # 같은 부위끼리 계수
    coordi = Counter(i[1] for i in clothes).values()
    # 매치할 수 있는 경우의 수: 부분집합의 개수
    # 근데 부분집합은 O(2^n)..
    # 고등학교 수학문제 곱의 법칙
    for coo in coordi:
        answer *= coo + 1
    return answer - 1