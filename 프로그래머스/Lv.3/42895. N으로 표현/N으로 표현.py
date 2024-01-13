# 연산 결과가 같은 게 많겠지.. 집합
def calculator(A, B):
    result = set()
    for a in A:
        for b in B:
            result.add(a+b)
            result.add(a-b)
            result.add(a*b)
            if b:
                result.add(a//b)
    return result

def solution(N, number):
    answer = -1
    operand = dict()
    operand[1] = {N}
    
    if N == number:
        return 1
    
    # 최대 8번까지 연산
    for n in range(2, 9):
        i = 1
        temp = {int(str(N)*n)}
        while i < n:
            temp.update(calculator(operand[i], operand[n-i]))
            i += 1
        if number in temp:
            return n
        
        operand[n] = temp
    
    return answer