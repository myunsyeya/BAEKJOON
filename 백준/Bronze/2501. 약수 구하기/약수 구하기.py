N, K = [*map(int, input().split())]
i = 0
while K:
    if i > N:
        print(0)
        break
    i += 1
    if N % i == 0:
        K -= 1
else:
    print(i)