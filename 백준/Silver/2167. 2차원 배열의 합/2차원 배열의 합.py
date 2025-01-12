N, M, *lis = map(int, open(0).read().split())
board = [lis[i*M:(i+1)*M] for i in range(N)]
lis = lis[N*M:]
K = lis.pop(0)
lis = [lis[i*4:(i+1)*4] for i in range(K)]
prefix = [[0] * (M+1) for _ in range(N+1)]

for i in range(1, N+1):
    for j in range(1, M+1):
        prefix[i][j] = board[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1]

for l in lis:
    i, j, x, y = l
    print(prefix[x][y] - prefix[i-1][y] - prefix[x][j-1] + prefix[i-1][j-1])