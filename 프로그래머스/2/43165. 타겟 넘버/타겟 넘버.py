answer = 0
def solution(numbers, target):
    global answer
    def dfs(target, idx):
        global answer
        if len(numbers) == idx:
            if not target:
                answer += 1
            return
        dfs(target - numbers[idx], idx+1)
        dfs(target + numbers[idx], idx+1)
    dfs(target, 0)
    return answer