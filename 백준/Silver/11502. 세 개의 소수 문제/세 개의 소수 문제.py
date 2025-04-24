primes = [2, 3]
for i in range(5, 1001, 2):
    if all(i % p for p in primes if p * p <= i):
        primes.append(i)

def find_three_sum(k):
    for i in primes:
        for j in primes:
            z = k - i - j
            if z in primes:
                return f'{i} {j} {z}'

for _ in range(int(input())):
    print(find_three_sum(int(input())))