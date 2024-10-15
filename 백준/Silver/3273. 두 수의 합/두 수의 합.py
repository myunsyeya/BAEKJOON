N, *lis = map(int, open(0).read().split())
x = lis[-1]
lis = set(lis[:-1])
answer = 0

for i in lis:
    if x-i in lis: answer+=1
print(answer//2)