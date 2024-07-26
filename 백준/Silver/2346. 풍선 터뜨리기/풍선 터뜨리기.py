from collections import deque

N, *paper = map(int, open(0).read().split())
paper = enumerate(paper, start=1)
paper = deque(paper)

while paper:
    turn = paper.popleft()
    bias = 0
    if turn[1] > 0: bias = -1
    paper.rotate(-turn[1]-bias)
    print(turn[0], end=" ")