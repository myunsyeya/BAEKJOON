from bisect import bisect_left
M, N = map(int, input().split())
prime, spf = [], [0]*(N+1)
# euler's sieve
for i in range(2, N+1):
    if not spf[i]:
        prime.append(i)
    for p in prime:
        if i*p > N: break
        spf[i*p] = i
        if not i % p: break

for i in range(bisect_left(prime, M), len(prime)):
    print(prime[i])