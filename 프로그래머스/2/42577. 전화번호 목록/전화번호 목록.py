def solution(phone_book):
    answer = True
    dic = {i: 1 for i in phone_book}
    for phone in phone_book:
        for i in range(len(phone)):
            if phone[:i] in dic and phone[:i] != phone:
                answer = False
    return answer