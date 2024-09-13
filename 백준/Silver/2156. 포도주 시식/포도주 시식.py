N, *lis = map(int, open(0))
dp = [0]*N
dp[0] = lis[0]
if len(dp)>1: dp[1] = sum(lis[:2])
if len(dp)>2: dp[2] = max(dp[1], lis[1]+lis[2], lis[0]+lis[2])

for i in range(3, N):
    dp[i] = max(dp[i-2]+lis[i], dp[i-3]+lis[i-1]+lis[i], dp[i-1])
print(max(dp))