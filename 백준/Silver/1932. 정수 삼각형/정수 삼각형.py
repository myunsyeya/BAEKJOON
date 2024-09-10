N, *lis = [*open(0)]
lis = [[*map(int, l.split())] for l in lis]
for l in reversed(range(len(lis)-1)):
    for i in range(len(lis[l])):
        lis[l][i]+=max(lis[l+1][i], lis[l+1][i+1])
print(lis[0][0])