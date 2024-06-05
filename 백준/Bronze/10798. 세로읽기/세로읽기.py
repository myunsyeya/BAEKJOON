line = 0
matrix = [input() for _ in range(5)]
string = ""
line = max(line, *(len(row) for row in matrix))
for col in range(line):
    for row in range(5):
        if len(matrix[row]) > col:
            string += matrix[row][col]
print(string)