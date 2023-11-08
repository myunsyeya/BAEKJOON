def solution(numbers):
    answer = ''
    answer = ''.join(sorted(list(map(str,numbers)), key=lambda x: (x*4)[:4], reverse=True))
    return answer if int(answer[0]) else "0"