N, M, *wood = map(int, open(0).read().split())
le, ri = 0, int(1e9)
h = 0

while le <= ri:
    mid = le + ri >> 1
    got_it = sum([x-mid if x-mid > 0 else 0 for x in wood])
    if got_it >= M:
        h = mid
        le = mid + 1
    else:
        ri = mid - 1
print(h)