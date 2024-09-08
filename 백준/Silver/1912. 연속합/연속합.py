N, *dp = map(int, open(0).read().split())
for i in range(1, len(dp)):
    dp[i] += dp[i-1] if dp[i-1]>0 else 0
print(max(dp))