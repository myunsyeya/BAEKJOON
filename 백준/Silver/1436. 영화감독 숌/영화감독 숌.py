N = int(input())
# 1e8/666 = 150150
for i in range(int(1e8)):
    if str(i).find('666') != -1:
        N -= 1
    if not N:
        print(i)
        break