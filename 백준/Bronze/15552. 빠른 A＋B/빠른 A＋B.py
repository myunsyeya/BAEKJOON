import sys

def finput():
    return sys.stdin.readline().rstrip()

T = int(finput())
for _ in range(T):
    A, B = map(int, finput().split())
    print(A+B)