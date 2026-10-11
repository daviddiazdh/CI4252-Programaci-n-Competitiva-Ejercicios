coords = [[1,3], [3,2], [3,5], [6,9], [10,1], [12,4], [5,7]]

i = 0
j = 0
mindist = 10000000000000
dist = 0
for cord in coords: 
    dist = 0
    for cordp in coords:
        if i != j:
            dist += abs(cord[0] - cordp[0]) + abs(cord[1] - cordp[1])
        j += 1
    if dist < mindist:
        mindist = dist
    i += 1

print(mindist)