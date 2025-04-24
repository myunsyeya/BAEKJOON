prime = [2, 3]
for i in range(5, 1001, 2):
    if any(i % p == 0 for p in prime) == False:
        prime.append(i)

def find_three_sum(K):
    for i in prime:
        for j in prime:
            for k in prime:
                if i + j + k == K:
                    return f'{i} {j} {k}'

def testflight(T):
    for t in range(T):
        K = int(input())
        print(find_three_sum(K))

testflight(int(input()))