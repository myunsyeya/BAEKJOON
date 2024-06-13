#def recur(p):
#    return p + p-1
# a_(n+1) = 2*a_n - 1
# a_(n+1)-1 = 2*(a_n-1)
# b_(n+1) = 2b_n
# b_n = b_1*2^(n-1)
# a_n-1 = (3-1)*2^(n-1), because a_1 = 3
# a_n = 2^n+1

N = int(input())
print((2**N+1)**2)