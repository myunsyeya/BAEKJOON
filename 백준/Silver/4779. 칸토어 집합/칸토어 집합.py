def go(n):
    if not n: return '-'
    return go(n-1) + ' '*3**(n-1) + go(n-1)

for N in map(int, [*open(0)]):
    print(''.join(go(N)))