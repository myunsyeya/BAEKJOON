from collections import Counter

A, B, C = int(input()), int(input()), int(input())
count = Counter(str(A*B*C))
for i in [str(_) for _ in range(10)]:
    print(0) if i not in count else print(count[i])