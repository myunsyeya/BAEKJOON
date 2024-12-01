for line in [*open(0)]:
    N, S = map(int, line.split())
    print(S//(N+1))