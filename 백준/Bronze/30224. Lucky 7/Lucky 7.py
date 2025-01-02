N = input()
answer = 0 if '7' not in N else 2
print(answer+(0,1)[int(N)%7 == 0])