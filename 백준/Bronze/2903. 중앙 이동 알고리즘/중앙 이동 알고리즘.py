def recur(p):
    return p + p-1

N = int(input())
point = 2
for _ in range(N): 
    point = recur(point)
print(point**2)