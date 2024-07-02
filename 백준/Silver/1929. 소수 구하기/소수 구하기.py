def sieve_of_eratosthenes(M, N):
    sieve = [True] * (N + 1)
    sieve[0] = sieve[1] = False
    
    for p in range(2, int(N**0.5) + 1):
        if sieve[p]:
            for multiple in range(p * p, N + 1, p):
                sieve[multiple] = False
    
    primes = [num for num in range(M, N + 1) if sieve[num]]
    return primes

# Example usage
M, N = map(int, input().split())
for p in sieve_of_eratosthenes(M, N):
    print(p)