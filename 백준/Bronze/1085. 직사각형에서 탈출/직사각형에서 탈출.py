x, y, w, h = [int(i) for i in input().split()]
print(min(x, y, w-x, h-y))