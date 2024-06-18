M, N = int(input()), int(input())
prime = []

for i in range(M, N+1):
    for j in range(2, i):
        if i % j == 0:
            break
    else: prime.append(i)
if 1 in prime: prime.pop(0)

if prime:
    print(sum(prime))
    print(prime[0])
else:
    print(-1)