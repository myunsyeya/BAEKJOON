while True:
    name, years, weight = input().split()
    years = int(years)
    weight = int(weight)
    if name == '#': break
    if years > 17 or weight >= 80:
        print(name, "Senior")
    else:
        print(name, "Junior")