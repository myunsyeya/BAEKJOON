N, M, *lis = map(int, open(0).read().split())
sixth = min(lis[::2])
ordi = min(lis[1::2])
answer = 0

answer += min(N//6*sixth, N//6*6*ordi)
answer += min(sixth, N%6*ordi)
print(answer)