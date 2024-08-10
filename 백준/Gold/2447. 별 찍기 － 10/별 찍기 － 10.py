N = int(input()) 

def go(n):
    if n == 1: return '*'
    Stars = go(n//3)
    L = []
    for star in Stars:
        L.append(star*3)
    for star in Stars:
        L.append(star+' '*(n//3)+star)
    for star in Stars:
        L.append(star*3)
    return L

print('\n'.join(go(N)))