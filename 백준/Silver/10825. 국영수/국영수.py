N = int(input())
lis = []
for _ in range(N): lis.append(input().split())
for i in sorted(lis, key=lambda x: (-int(x[1]),int(x[2]),-int(x[3]),x[0])): print(i[0])