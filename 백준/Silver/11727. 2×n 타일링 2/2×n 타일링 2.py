N = int(input())

memo = [0, 1, 3]
for i in range(3,N+1): memo.append((memo[i-1] + memo[i-2]*2)%10007)
print(memo[N])