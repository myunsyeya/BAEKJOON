N, *lis = [int(i) for i in open(0).read().split()]
count = 0
for n in lis:
    i = 2
    if n == 1:
        continue
    if n == 2 or n == 3:
        count += 1
        continue
    while i*i <= n:
        if n % i == 0:
            break
        i += 1
    else: count += 1
print(count)