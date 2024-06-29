fn, fn_c = map(int, input().split())
c = int(input())
n_0 = int(input())

print((0,1)[fn*n_0+fn_c <= c*n_0 and fn <= c])