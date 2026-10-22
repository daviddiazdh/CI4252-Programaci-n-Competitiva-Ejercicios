import bisect

t = int(input())

# Cuando queremos hacer la comparación de todos los puntos debemos
# hacer para cada punto p_k = (x_k, y_k) lo siguiente

#           sum_(i=0 -> n)(x_i - x_k) + sum_(i=0 -> n)(y_i - y_k)

# con 0 <= k < n.

# Notemos que el valor absoluto presenta dos casos
#                           x_i - x_k    si  x_k <= x_i
#           |x_i - x_k| = 
#                           x_k - x_i    si  x_k > x_i

# Para los valores que son mayores a x_k, yo podría simplemente hacer
#               (+x | x < x_k : 1) * x_k - (+x | x < x_k : x)
# Esto también aplicaría exactamente igual para y.

# Notemos que la relación es de orden, por lo que conviene ordenar
# previamente las coordenadas para saber la relación de orden entre todas, 
# para luego poder construir un arreglo de prefijos que guarde estas sumatorias.

#      P[k] simboliza la sumatoria de todos los elementos menores a x_(k) incluyendo x_(k)

# note el uso de (k) para indicar el índice sobre el arreglo ordenado.
# De esa manera, tendríamos que la sumatoria de los menores sería 

#                           (k + 1) * x_(k) - P[k]

# Y para la de los mayores requerimos en una fase previa guardar el valor (+x | true : x) = X, así

#                           (X - P[k]) - (n - k - 1) * x_(k)

# con esto, la suma se resuelve rápidamente.
# El único problema es que las coordenadas originales no van a coincidir en índice con las 
# coordenadas de los arreglos de ordenados por cada coordenada, eso quiere decir que, para cada amigo, 
# debemos buscar la posición en la que quedó en el arreglo dado, para ello usamos búsqueda binaria 
# en ambos arreglos, con eso detectamos el índice k que lo representa en cada arreglo y podemos usar 
# tranquilamente el cálculo.

while t != 0:

    coords = []
    X = []
    Y = []
    f = int(input())
    n = f
    while f != 0:
        coord = list(map(int, input().split()))
        coords.append(coord)
        X.append(coord[0])
        Y.append(coord[1])
        f -= 1

    # Ordenamos las coordenadas
    X.sort()
    Y.sort()

    # Hacemos el arreglo de prefijos de X
    accum = 0
    sumPrefixX = []
    i = 0
    for x in X:
        accum += x
        sumPrefixX.append(accum)
        i += 1
    accumX = accum

    # Hacemos el arreglo de prefijos de Y
    accum = 0
    sumPrefixY = []
    i = 0
    for y in Y:
        accum += y
        sumPrefixY.append(accum)
        i += 1
    accumY = accum

    mindist = 100000000000000
    # Implementamos la búsqueda binaria sobre el arreglo de prefijos
    for coord in coords:
        dist = 0
        indexX = bisect.bisect_right(X, coord[0]) - 1
        indexY = bisect.bisect_right(Y, coord[1]) - 1
        dist += (indexX + 1) * X[indexX] - sumPrefixX[indexX]
        dist += (accumX - sumPrefixX[indexX]) - (n - indexX - 1) * X[indexX]

        dist += (indexY + 1) * Y[indexY] - sumPrefixY[indexY]
        dist += (accumY - sumPrefixY[indexY]) - (n - indexY - 1) * Y[indexY]
        if(dist < mindist):
            mindist = dist

    print(mindist)

    t -= 1