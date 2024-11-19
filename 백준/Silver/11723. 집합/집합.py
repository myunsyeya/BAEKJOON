import sys
input = sys.stdin.readline

s = [0] * 20
for _ in range(int(input().strip())):
    cmd = input().strip().split()
    
    if cmd[0] == "all":
        for i in range(20): s[i] = 1
    elif cmd[0] == "empty":
        for i in range(20): s[i] = 0
    else:
        x = int(cmd[1]) - 1  # 0-based index
        if cmd[0] == "add":
            s[x] = 1
        elif cmd[0] == "remove":
            s[x] = 0
        elif cmd[0] == "check":
            print(s[x])
        elif cmd[0] == "toggle":
            s[x] ^= 1
