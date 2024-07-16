T = int(input())
for _ in range(T):
    N = int(input())
    if N == 0 or N == 1: N = 2
    while True:
        if not N % 2 and N != 2: N += 1
        elif not N % 3 and N != 3: N += 2
        for i in range(2, int(N**0.5+1)):
            if N%i == 0: break
        else: break
        N += 1
    print(N if N != 1 and N != 0 else 2)