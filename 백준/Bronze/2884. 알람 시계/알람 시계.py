H, M = map(int, input().split())
H = H if M >= 45 else 23 if not H else H - 1
M = M - 45 if M >= 45 else M + 15
print(H, M)