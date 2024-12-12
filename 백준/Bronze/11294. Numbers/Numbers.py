lis = [*open(0)]
keys = lis[::3][:-1]
digits = lis[1::3]
nums = lis[2::3]

dic = {i: (chr(ord('A') + i - 10) if i >= 10 else str(i)) for i in range(20)}

for i in range(len(keys)):
    num = int(nums[i])
    digit = int(digits[i])
    string = []
    while num: string.insert(0,dic[num%digit]); num//=digit
    print(f'{keys[i].strip()}, {nums[i].strip()}, {"".join(string)}')