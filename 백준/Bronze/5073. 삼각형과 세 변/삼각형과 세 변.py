angle = {0:"Invalid", 1:"Scalene", 2:"Isosceles", 3:"Equilateral"}
while True:
    tri = [*map(int, input().split())]
    if 0 in tri: break
    elif sum(tri) - 2*max(tri) > 0: print(angle[max(tri.count(tri[0]), tri.count(tri[1]))])
    else: print(angle[0])