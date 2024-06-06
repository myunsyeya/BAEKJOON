N = int(input())

for i in range(2*N-1):
    # star is 2*N-1 - 2*abs(N-i-1) = 2*(N-abs(N-i-1))-1
    # space 2*N-1 - star
    star = 2*(N-abs(N-i-1))-1
    space = (2*N-1-star)//2
    for _ in range(space):
        print(' ', end="")
    for _ in range(star):
        print('*', end="")
    print("")