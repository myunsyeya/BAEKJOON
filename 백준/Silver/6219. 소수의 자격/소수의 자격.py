A, B, C = map(int, input().split())
C = str(C)
seive = [1] * (B + 1)
answer = 0

if A <= 2 <= B and '2' in C: answer += 1

for i in range(3, B + 1, 2):
    if seive[i]:
        if i >= A and C in str(i): answer += 1
        if i * i <= B: seive[i*i::i*2] = [0]*((B-i*i)//(i*2)+1)

print(answer)