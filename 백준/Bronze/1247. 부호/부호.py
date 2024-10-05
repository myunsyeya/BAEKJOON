lis = [*map(int, open(0))]
for _ in range(3):
    N = lis[0]
    answer = sum(lis[1:N+1])
    lis = lis[N+1:]
    print(0 if not answer else '-' if answer < 0 else '+')