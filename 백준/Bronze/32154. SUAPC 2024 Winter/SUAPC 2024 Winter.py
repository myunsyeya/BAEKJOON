scoreboard = {
    1:['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'L', 'M'],
    2:['A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M'],
    3:['A', 'C', 'E', 'F', 'G', 'H', 'I', 'L', 'M'],
    4:['A', 'B', 'C', 'E', 'F', 'G', 'H', 'L', 'M'],
    5:['A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'],
    6:['A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'],
    7:['A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'],
    8:['A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'],
    9:['A', 'C', 'E', 'F', 'G', 'H', 'L', 'M'],
    10:['A', 'B', 'C', 'F', 'G', 'H', 'L', 'M']
}

N = int(input())

print(len(scoreboard[N]))
print(' '.join(scoreboard[N]))