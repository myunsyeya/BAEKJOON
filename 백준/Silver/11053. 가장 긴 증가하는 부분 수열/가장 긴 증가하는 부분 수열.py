N, *lis = map(int, open(0).read().split())
dp = [1]*N
for i in range(1, len(lis)):
    for j in range(i):
        if lis[j]<lis[i] and dp[j]+1>dp[i]: dp[i]=dp[j]+1
print(max(dp))