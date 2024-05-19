N = int(input())
for i in range(1, N+1):
    print(''.rjust(N-i, ' ') + '*'*i)