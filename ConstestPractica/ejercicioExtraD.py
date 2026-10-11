
line = list(map(int, input().split()))
n = line[0]
m = line[1]

ranges = []

for i in range(0, m):
    line = list(map(int, input().split()))
    islandA = line[0]
    islandB = line[1]
    ranges.append([islandA, islandB])

ranges_sorted = sorted(ranges, key=lambda x : x[1])

lastRL = 0
bridges = 0
for element in ranges_sorted:
    if element[0] >= lastRL:
        bridges += 1
        lastRL = element[1]

print(bridges)

