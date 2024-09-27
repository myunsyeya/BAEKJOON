A, B, C = map(int, input().split())
prime = []
toB = [1]*(B+1)
answer = 0

for i in range(2, B+1):
    if toB[i]: 
        if i >= A: prime.append(i)
        for j in range(i, B+1, i): toB[j] = 0
for p in prime:
    answer += str(p).find(str(C)) != -1
print(answer)