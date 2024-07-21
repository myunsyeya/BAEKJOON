N, *stu = map(int, open(0).read().split())
stack = list()
start = 1

for s in stu:
    stack.append(s)
    while stack and stack[-1] == start:
        stack.pop()
        start += 1

print("Sad" if stack else "Nice")