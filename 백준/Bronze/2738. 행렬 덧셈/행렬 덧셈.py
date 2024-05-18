import sys
input = sys.stdin.readline

N, M = map(int, input().split())
X = [[int(x_i) for x_i in input().split()] for _ in range(N)]
Y = [[int(x_i) for x_i in input().split()] for _ in range(N)]
S = [[x_i + y_i for x_i, y_i in zip(x, y)] for x, y in zip(X,Y)]

for row in S:
    print(*row)