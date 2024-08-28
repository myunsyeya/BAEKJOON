S1, S2, S3 = map(int, input().split())
sum_dict = {}
for s1 in range(1,S1+1):
    for s2 in range(1,S2+1):
        for s3 in range(1,S3+1):
            if s1+s2+s3 not in sum_dict:
                sum_dict[s1+s2+s3] = 1
            else: sum_dict[s1+s2+s3]+=1
print(sorted(sum_dict.items(), reverse=True, key=lambda x:x[1])[0][0])