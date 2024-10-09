lis = [s.rstrip() for s in open(0)]
idx = 0
week = 1
while lis[idx] != '0':
    n = int(lis[idx])
    cnt = dict()
    for tok in lis[idx+1:idx+n+1]: cnt[tok] = 0
    print(f'Week {week} {len(cnt)}')
    idx += n+1
    week+=1