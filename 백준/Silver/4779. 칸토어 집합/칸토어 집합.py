def go(S, l, r):
    div = (r-l+1)//3
    if r>l+div-1: go(S, l, l+div-1)
    if r-div+1>l: go(S, r-div+1, r)
    for i in range(div): S[l+div+i] = ' '

for N in map(int, [*open(0)]):
    string = ['-']*3**N
    go(string, 0, 3**N-1)
    print(''.join(string))