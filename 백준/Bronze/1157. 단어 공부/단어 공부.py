from collections import Counter

string = input().upper()
sup = Counter(string).most_common(2)
print(sup[0][0]) if len(sup) == 1 or sup[0][1] > sup[1][1] else print('?')