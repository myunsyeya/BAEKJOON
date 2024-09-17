N, *lis = map(int, open(0).read().split())
asend = [0]*1001
dp = asend[:]
for i in lis: asend[i]=max(asend[:i])+1; dp[i]=max(dp[i+1:]+asend[:i])+1
print(max(dp))