def list_factors(n):
    left, right = [1], []
    for i in range(2, int(n**0.5+1)):
        if n % i == 0:
            left.append(i) or (n != i*i) and right.append(n//i)
    return left + right[::-1]

def vsprint(n, factors):
    print(f"{n} = {' + '.join(map(str, factors))}")

while True:
    N = int(input())
    if N == -1: break
    if N == sum(factors := list_factors(N)):
        vsprint(N, factors)
    else: print(N, "is NOT perfect.")    