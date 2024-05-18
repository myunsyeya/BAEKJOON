absence = list(range(1, 31))
for _ in range(28):
    absence.remove(int(input()))
print(*sorted(absence))