while True:
    A, B = [*map(int, input().split())]
    if not A and not B: break
    if not B % A: print("factor")
    elif not A % B: print("multiple")
    else : print("neither")