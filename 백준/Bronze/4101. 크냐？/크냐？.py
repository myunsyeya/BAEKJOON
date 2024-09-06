lis = [*open(0)][:-1]
for i in lis: 
    a, b = map(int, i.split())
    print('Yes' if a>b else 'No')