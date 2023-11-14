from itertools import permutations
# 2^7 => 부분집합의 개수는 128개. 순서 고려 시 7! = 5040 
# 퍼뮤테이션 이용 후 소수 집합이랑 매칭되는 요소 개수가 답.
def solution(numbers):
    answer = 0
    articles = []
    prime = prime_list(10**len(numbers))
    for article in [list(permutations(numbers,i)) for i in range(1,7)]:
        for paper in article:
            articles.append(int(''.join(paper)))
    articles = set(articles)
    for article in articles:
        if article in prime:
            answer += 1
            prime.remove(article)
    return answer

def prime_list(I):
    for i in range(2, I):
        if I < i*i:
            root = i
            break
    Sieve = [True] * I

    for i in range(2, root):
        if Sieve[i]:
            for j in range(i+i, I, i):
                Sieve[j] = False

    return [i for i in range(2, I) if Sieve[i]]