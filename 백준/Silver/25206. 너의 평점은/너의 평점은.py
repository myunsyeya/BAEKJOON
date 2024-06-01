score = 0.0
default = 0.0
grade = {'A+':4.5, 'A0':4.0, 'B+':3.5, 'B0':3.0, 'C+':2.5, 'C0':2.0, 'D+':1.5, 'D0':1.0, 'F':0.0}
for _ in range(20):
    obj = input().split()
    if obj[2] != "P":
        score += float(obj[1])*grade[obj[2]]
        default += float(obj[1])
print(score/default)