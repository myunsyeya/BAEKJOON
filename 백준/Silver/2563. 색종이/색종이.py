N = int(input())
MAP = [[0 for _ in range(100)] for _ in range(100)]
for i in range(N):
    left, down = [int(i) for i in input().split()]
    for row in range(10):
        for col in range(10):
            MAP[row+down][col+left] = 1
print(sum(MAP,[]).count(1))