def solution(triangle):
    answer = 0
    
    for depth in range(len(triangle)-1, 0, -1):
        for i in range(len(triangle[depth])-1):
            triangle[depth-1][i] += max(triangle[depth][i], triangle[depth][i+1])
    return triangle[0][0]