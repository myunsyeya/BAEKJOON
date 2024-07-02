a, b, c, d, e, f = map(int, input().split())
# Cramer's Rule
det = a*e-b*d
dx = c*e-b*f
dy = a*f-c*d
print(dx//det, dy//det)
# -999~999 => 2*1000 ** 2 -> 4*1e6 
#for x in range(-999, 1000):
#    for y in range(-999, 1000):
#        if not (a*x+b*y-c or d*x+e*y-f):
#            print(x, y)
#            break
#    else: continue
#    break