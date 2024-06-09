N, notation = [s for s in input().split()]
N, notation = reversed(N), int(notation)
decimal = 0
digit = 1

for i in N:
    decimal += (ord(i)-ord('0'))*digit if ord(i) < ord('A') else (ord(i)-ord('7'))*digit
    digit *= notation
print(decimal)