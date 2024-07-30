import sys
input = sys.stdin.readline

N = int(input().rstrip())
nickname = dict()
answer = 0
while N:
    string = input().rstrip()
    N-=1
    if string == "ENTER":
        nickname = dict()
        continue
    if not string in nickname:
        nickname[string] = True
        answer += 1
print(answer)