# 도수정렬을 생각해보면, i번째 칸 이후에 가장 큰 숫자+1을 택하면 된다.
N, *lis = map(int, open(0).read().split())
dp = [0]*1002
for i in lis: dp[i]=max(dp[i+1:])+1
print(max(dp))