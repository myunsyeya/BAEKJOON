N, m, M, T, R = map(int, input().split())
answer = 0
now = m
while N:
    if not N: break
    answer+=1
    if now+T<=M: now+=T; N-=1; continue
    elif now == m: answer=-1; break
    else: now = m if now-R<m else now-R; continue

print(answer)