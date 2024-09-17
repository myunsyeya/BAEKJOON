N, *lis = map(int, open(0).read().split())
asend = [1]*N
dsend = [1]*N
for i in range(1, len(lis)):
    for j in range(i):
        if lis[j]<lis[i] and asend[j]+1>asend[i]: asend[i]=asend[j]+1
for i in range(len(lis)-2, -1, -1):
    for j in range(len(lis)-1, i, -1):
        if lis[j]<lis[i] and dsend[j]+1>dsend[i]: dsend[i]=dsend[j]+1
print(max(x+y for x,y in zip(asend, dsend))-1)