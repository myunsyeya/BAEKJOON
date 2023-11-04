def solution(s):
    answer = True
    
    basket = []
    for i in s:
        if i == '(':
            basket.append(0)
        else:
            if not basket:
                return False
            basket.pop()
    if basket:
        answer = False
    return answer