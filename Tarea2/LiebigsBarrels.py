# Utilizo también una estrategia greedy, la idea es primeramente
# partir del hecho de que la tabla de menor longitud (digamos, longitud m)
# siempre va a ser un volumen de alguno de los buckets. Dado este hecho, 
# podemos armar el conjunto de tablas válidas o factibles (por llamarlo de 
# algún modo) es un conjunto de tablas cuya diferencia en longitud con m 
# no supera l (el límite establecido por el enunciado).
# Con esa información, podemos saber rápidamente si el problema tiene o no
# solución, dado que si la cardinalidad de este conjunto es menor que n, entonces
# no existe forma de armar n buckets sin romper la condición de que sus volúmenes
# no difieran por más de l. A dicha cardinalidad la llamamos valid_count.

# Si ya sabemos que el problema tiene solución, entonces usamos la estrategia
# greedy que consiste en ordenar las tablas de menor a mayor, empezar por el mínimo 
# y decidir siempre entre dos opciones:
#   - Tomar la siguiente tabla como la tabla a k saltos de la actual
#   - Simplemente tomar la siguiente en el conjunto de las tablas válidas
# La idea de la estrategia es tomar un volumeno mayor, mientras más a la derecha vayas
# más mayor estás haciendo el volumen, pero eso solo se puede hacer si te quedan 
# suficientes tablas en el conjunto válido para hacer los buckets, por eso se sujeta a
# la siguiente condición:
#       idx = min(idx + k, valid_count - n + (i + 1))

# Entrada de datos
first_line = list(map(int, input().split()))
n = first_line[0]
k = first_line[1]
l = first_line[2]
a = list(map(int, input().split()))

# Ordenamos las tablas de menor a mayor según su longitud
a.sort()

# Verificamos si el problema tiene solución, mirando
# si la cardinalidad del conjunto de tablas válidas es
# mayor que n 
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
    # Si el problema tiene solución aplicamos la estrategia greedy
    total_volume = 0
    idx = 0
    for i in range(n):
        total_volume += a[idx]
        # Siempre queremos que los buckets contengan el mínimo más grande posible,
        # pero no se agoten las tablas válidas
        idx = min(idx + k, valid_count - n + (i + 1))
    print(total_volume)