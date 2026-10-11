arreglo = list(map(int, input().split()))
arreglo.sort()

i = 0
n = len(arreglo)
accum = 0
while(i < n):
    if(i != n - 1):
        accum += arreglo[i+1] - arreglo[i]
    i += 1

print(accum)
