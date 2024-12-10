A, B = map(int, input().split())
K, X = map(int, input().split())

lb = K-X if A <= K-X else A
ub = K+X if K+X <= B else B

print(ub - lb + 1 if ub - lb + 1 > 0 else "IMPOSSIBLE")