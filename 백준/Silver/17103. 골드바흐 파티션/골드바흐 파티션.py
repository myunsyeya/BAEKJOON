max_N = 1_000_000+1
era = [1]*max_N
era[0]=era[1]=0
for i in range(int(max_N**0.5)+1):
    if era[i]:
        for j in range(i*i, max_N, i): era[j]=0
prime = [i for i in range(max_N) if era[i]]

T, *N = map(int, [*open(0)])
for n in N:
    part = 0
    for p in prime:
        if p+p > n: break
        if era[n-p]: part+=1
    print(part)