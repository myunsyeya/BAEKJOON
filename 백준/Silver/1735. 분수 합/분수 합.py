A, B, C, D = map(int, open(0).read().split())

def __gcd(a, b):
    if not b: return a
    return __gcd(b, a%b)

top = A*D+B*C
down = B*D
gcd = __gcd(top, down)
print(top//gcd, down//gcd)