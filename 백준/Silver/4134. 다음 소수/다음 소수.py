T = int(input())
for _ in range(T):
    N = int(input())
    while True:
        for i in range(2, int(N**0.5+1)):
            if N%i == 0: break
        else: break
        N += 1
    print(N if N != 1 and N != 0 else 2)