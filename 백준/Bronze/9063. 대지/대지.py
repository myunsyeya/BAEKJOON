N, *point = map(int, open(0).read().split())
dist = lambda x:max(x)-min(x)
print(dist(point[::2])*dist(point[1::2]))