import sys
input = sys.stdin.readline

N, X = map(int, input().split())
A = [a for a in input().split() if int(a) < X]
print (*A)