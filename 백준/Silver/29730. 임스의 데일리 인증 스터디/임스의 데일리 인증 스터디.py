N, *lis = [*open(0)]
frag = 'boj.kr/'
lis = [l.strip() for l in lis]
boj = [l.split(frag)[1] for l in lis if frag in l]
lis = [l for l in lis if frag not in l]

for l in sorted(lis, key=lambda x : (len(x), x)): print(l)
for b in sorted(boj, key=lambda x: int(x)): print(frag + b)