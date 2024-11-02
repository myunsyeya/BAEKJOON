N, *lis = [*open(0)]
rot_lis = [''.join(l[i] for l in lis) for i in range(int(N))]

print(sum(map(lambda row: sum('..' in r for r in row.split('X')), lis)), end=' ')
print(sum(map(lambda col: sum('..' in c for c in col.split('X')), rot_lis)))