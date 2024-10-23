A, B, N = map(int, input().split())
print(A*pow(10,N,B*10)//B%10)