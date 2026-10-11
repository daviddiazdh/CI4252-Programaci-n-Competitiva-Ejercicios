items = list(map(int, input().split()))
n = items[0]
d = items[1]

people = list(map(int, input().split()))
index_people = sorted(enumerate(people, start=1), key=lambda x: x[1])

aparts = []

for i in range(0, n):
    left_cond = True
    if i - 1 >= 0:
        distance = index_people[i][1] - index_people[i - 1][1]
        if distance < d:
            left_cond = False

    right_cond = True
    if i + 1 < n:
        distance = index_people[i + 1][1] - index_people[i][1]
        if distance < d:
            right_cond = False

    if left_cond and right_cond:
        aparts.append(index_people[i][0])

aparts.sort()
print(len(aparts))

for a in aparts:
    print(a, end=" ")
