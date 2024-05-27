from collections import Counter
N = int(input())
for _ in range(N):
    Two = Counter(''.join(input().split())).most_common(2)
    if len(Two) == 1 or Two[0][1] != Two[1][1]:
        print(Two[0][0])
    else : print('?')