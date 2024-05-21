string = list({input() for _ in range(int(input()))})
for word in sorted(string, key=lambda x : (len(x), x)):
    print(word)