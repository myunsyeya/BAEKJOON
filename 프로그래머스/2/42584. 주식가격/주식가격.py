def solution(prices):
    answer = [1]*(len(prices)-1)+[0]
    
    for idx, num in enumerate(prices[:-1]):
        cnt = 0
        for i in range(idx+1, len(prices)):
            cnt+=1
            if num > prices[i]:
                break
        answer[idx] = cnt
    return answer