T, *lis = map(int, [*open(0)])
answer = [1, 1, 1, 2, 2, 3, 4, 5, 7, 9]
for i in range(10, 101):
    answer.append(answer[i-3]+answer[i-2])
for l in lis:
    print(answer[l-1])