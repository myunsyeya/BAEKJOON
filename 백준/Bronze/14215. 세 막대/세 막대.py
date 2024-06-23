#WLOG a+b = c
# ((a+b)*2)-1
tri = [*map(int, input().split())]
tri.sort()
print(((sum(tri)-tri[2])*2-1, sum(tri))[sum(tri)>tri[2]*2])