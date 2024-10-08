D, H, W = map(int, input().split())
h = (W*W + H*H)**0.5
print(int(D*H/h), int(D*W/h))