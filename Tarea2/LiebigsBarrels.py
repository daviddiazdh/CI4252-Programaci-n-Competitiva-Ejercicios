first_line = list(map(int, input().split()))

n = first_line[0]
k = first_line[1]
l = first_line[2]

a = list(map(int, input().split()))

a.sort()

limit = a[0] + l

valid_count = 0
for stave in a:
    if stave <= limit:
        valid_count += 1
    else:
        break
        
if valid_count < n:
    print(0)
    
else:
    total_volume = 0
    idx = 0
    
    for i in range(n):
        total_volume += a[idx]
        
        idx = min(idx + k, valid_count - n + (i + 1))
        
    print(total_volume)