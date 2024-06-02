Max, row, col = 0, 1, 1
for r in range(9):
    for c, val in enumerate([int(_) for _ in input().split()]):
        if (val > Max):
            row, col = r+1, c+1
            Max = val
print(Max)
print(row, col)