import sys
input = sys.stdin.readline

N, series, v = int(input()), [int(s) for s in input().split()], int(input())
print(series.count(v))