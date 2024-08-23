answer = 0
for i in range(8):
    string = input()
    for s in string[i%2::2]:
        answer += s == 'F'
print(answer)