N, *lis = map(int, open(0).read().split())
x = lis[-1]
lis = lis[:-1]
answer = 0

le = 0
ri = len(lis)-1
lis.sort()
while le < ri:
    s = lis[le]+lis[ri]
    if s < x: le+=1
    elif s > x: ri-=1
    else: answer+=1; ri-=1; le+=1
print(answer)