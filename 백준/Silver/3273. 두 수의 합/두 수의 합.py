N, *lis = map(int, open(0).read().split())
x = lis[-1]
lis = lis[:-1]
answer = 0

chk = dict()
for i in lis:
    if x-i in chk: answer+=1
    chk[i] = True
print(answer)