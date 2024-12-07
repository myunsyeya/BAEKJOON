X = int(input())
lis = [64]
while sum(lis) > X:
    pivot = lis[-1]>>1
    lis.pop()
    if X > sum(lis)+pivot: lis.append(pivot)
    lis.append(pivot)
print(len(lis))