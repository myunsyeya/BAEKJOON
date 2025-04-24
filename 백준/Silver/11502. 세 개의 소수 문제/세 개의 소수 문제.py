primes = [2, 3]
for i in range(5, 1001, 2):
    if all(i % p for p in primes if p * p <= i):
        primes.append(i)

def find_three_sum(k):
    return next((f'{i} {j} {k - i - j}' for i in primes for j in primes if (k - i - j) in primes), 0)

for _ in range(int(input())):
    print(find_three_sum(int(input())))