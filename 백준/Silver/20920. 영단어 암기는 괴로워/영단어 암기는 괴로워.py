from collections import Counter

N, M, *words = open(0).read().split()
N, M = int(N), int(M)

# filtering by greater than M
words = [word for word in words if len(word) >= M]

words = Counter(words)
for word in sorted(words.keys(), key=lambda word: (-words[word], -len(word), word)):
    print(word)