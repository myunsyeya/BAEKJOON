A, B, C = map(int, input().split())
C = str(C)
toB = [1] * (B + 1)
answer = 0

if A <= 2 <= B and '2' in C: answer += 1

for i in range(3, B + 1, 2):
    if toB[i]:
        if i >= A and C in str(i): answer += 1
        for j in range(i * i, B + 1, i * 2): toB[j] = 0

print(answer)