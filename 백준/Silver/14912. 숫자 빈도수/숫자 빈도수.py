n, d = map(int, input().split())
answer = 0
for i in range(1, n+1):
    for c in str(i): answer+=(0,1)[str(d)==str(c)]
print(answer)