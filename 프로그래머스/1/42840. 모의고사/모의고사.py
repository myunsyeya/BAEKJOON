def solution(answers):
    answer = []
    droper1 = ([1,2,3,4,5] * (len(answers)//5 + 1))[:len(answers)]
    droper2 = ([2,1,2,3,2,4,2,5] * (len(answers)//8 + 1))[:len(answers)]
    droper3 = ([3,3,1,1,2,2,4,4,5,5] * (len(answers)//10 + 1))[:len(answers)]
    
    for idx in reversed(range(len(answers))):
        if droper1[idx] != answers[idx]:
            droper1.pop()
        if droper2[idx] != answers[idx]:
            droper2.pop()
        if droper3[idx] != answers[idx]:
            droper3.pop()
    match = [len(droper1), len(droper2), len(droper3)]
    higher = max(match)
    for idx in range(3):
        if higher == match[idx]:
            answer.append(idx + 1)
    return answer