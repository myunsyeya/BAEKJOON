N, F = int(input()), int(input())
N -= N%100
while N%F != 0: N+=1
print(N%100 if N%100 > 9 else f'0{N%100}')