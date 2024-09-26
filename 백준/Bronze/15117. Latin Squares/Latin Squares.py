N, *lis = [*open(0)]
N = int(N)
lis = [l.rstrip() for l in lis]
sq = [*range(N)]
red = 0
chk = 0

frow = [int(r) if r <= '9' else 10+ord(r)-ord('A') for r in lis[0]]
fcol = [int(c) if c <= '9' else 10+ord(c)-ord('A') for c in [lis[i][0] for i in sq]]
if frow == sq and fcol == sq: red = 1

for ro in sq:
    row = set(int(r) if r <= '9' else 10+ord(r)-ord('A') for r in lis[ro])
    if set(sq)-row: chk = 1; break

for co in sq:
    col = set(int(c) if c <= '9' else 10+ord(c)-ord('A') for c in [lis[i][co] for i in sq])
    if set(sq)-col: chk = 1; break
        
if not chk and red: print('Reduced')
elif not chk: print('Not Reduced')
else: print('No')