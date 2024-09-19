N, *lis = open(0)
li = []
for l in lis: li.append(l.split())
for i in sorted(li, key=lambda x: (-int(x[1]),int(x[2]),-int(x[3]),x[0])): print(i[0])