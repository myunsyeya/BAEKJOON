X, Y = 0, 0
for _ in range(3):
    x, y = map(int, input().split())
    X, Y = X^x, Y^y
print(X, Y)