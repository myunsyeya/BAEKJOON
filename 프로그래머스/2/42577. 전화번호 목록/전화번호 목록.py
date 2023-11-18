def solution(phone_book):
    answer = True
    dic = {i: 1 for i in phone_book}
    # O(20*n) = O(n)
    for phone in phone_book:
        for i in range(len(phone)):
            if phone[:i] in dic:
                answer = False
    return answer