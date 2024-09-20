N, *lis = map(int, open(0).read().split())
lis.sort()
print(lis[2*N-1]-lis[N])