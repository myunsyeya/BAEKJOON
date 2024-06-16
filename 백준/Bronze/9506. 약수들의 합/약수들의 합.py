def list_factors(n):
    # if n % 2 == 0, then factors_sup is n/2
    return [i for i in range(1, n//2+1) if n % i == 0]

def vsprint(n, factors):
    print(f"{n} = {' + '.join(map(str, factors))}")

for n in [int(i) for i in [*open(0)][:-1]]:
    if n==sum(factors := list_factors(n)):
        vsprint(n, factors)
    else: print(n, 'is NOT perfect.')