def int_input():
    return map(int, input().split())

def make_matrix(N):
    matrix_list = list()
    for _ in range(N):
        arr = list(int_input())
        matrix_list.append(arr)
    return matrix_list

N, M = int_input()
X = make_matrix(N)
Y = make_matrix(N)
S = [[x_i + y_i for x_i, y_i in zip(x, y)] for x, y in zip(X,Y)]

for row in S:
    print(*row)