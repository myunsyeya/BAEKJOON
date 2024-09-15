L, A, B, C, D = map(int, open(0))
print(L-max((A+C-1)//C, (B+D-1)//D))