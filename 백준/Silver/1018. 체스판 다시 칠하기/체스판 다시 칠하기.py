N, M = map(int, input().split())
board = list()
for _ in range(N):
    row = input()
    board.append(row)
white, black = list(), list()
chess_row = ['WBWBWBWB', 'BWBWBWBW']
for i in range(8):
    white.append(chess_row[i%2])
    black.append(chess_row[(i+1)%2])

answer = 64
for row in range(N-7):
    for column in range(M-7):
        wcnt, bcnt = 0, 0
        for r in range(8):
            for c in range(8):
                wcnt += 0 if white[r][c] == board[row+r][column+c] else 1
                bcnt += 0 if black[r][c] == board[row+r][column+c] else 1
        answer = min(answer, wcnt, bcnt)
print(answer)