M, N = int(input()), int(input())
spf = [0] * (N+1)
prime = []

# euler's sieve
for i in range(2, N+1):
    if not spf[i]:
        prime.append(i)
        spf[i] = i
    for p in prime:
        if i*p > N: break
        spf[i*p] = p
        if i % p == 0: break

answer = [i for i in range(M, N+1) if i in prime]

if answer:
    print(f'{sum(answer)}\n{answer[0]}')
else:
    print(-1)