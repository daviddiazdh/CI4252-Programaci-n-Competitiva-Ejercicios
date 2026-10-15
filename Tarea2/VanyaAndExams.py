# Aquí usamos también una estrategia greedy, la idea es ordenar los
# resultados de los exámenes en orden ascendente según la cantidad de 
# ensayos que se requieren hacer para aumentar un punto.
# Siempre es más conveniente hacer aquellos que tengan la menor
# cantidad de ensayos primero porque de todos modos cualquier aumento 
# en nota aporta lo mismo, 1/n, no importa si lo haces en el que pide
# menos ensayos o más ensayos, igualmente el aporte al promedio es 1/n.

# Es fácil calcular la nota necesaria para que el promedio supere avg, 
# esto es simplemente n * avg, siendo n la cantidad de exámenes, 
# la lógica de esto sale de lop siguiente, se quiere esto
#          (+r | r ∈ Resultados : r)/n >= avg
# despejando:
#          (+r | r ∈ Resultados : r) >= n * avg
# Es decir, la suma de los resultados debe ser al menos n * avg, si ya 
# es mayor o igual, entonces no hay que hacer ningún ensayo. Mientras sea 
# menor, hay que completar la nota máxima en los exámenes en orden
# ascendente según la cantidad de ensayos hasta que el promedio real sea 
# igual al n * avg. 

# Entradas
entry = list(map(int, input().split()))
n = entry[0]
r = entry[1]
min_avg = entry[2]

# Calculamos la suma de los resultados y guardamos los pares
greedy_exams = []
sum = 0
for i in range(0,n):
    grade_result = list(map(int, input().split()))

    grade = grade_result[0]
    essays = grade_result[1]

    sum += grade
    greedy_exams.append([grade, essays])

# Calculamos la suma ideal mínima
target_sum = n * min_avg

# Comparamos para el caso explicado arriba
if(sum < target_sum):

    # Calculamos los puntos necesarios para alcanzar n * avg
    needed_points = target_sum - sum
    greedy_exams.sort(key = lambda x: x[1])

    essays_done = 0
    for grade, essays in greedy_exams:

        can_add = r - grade
        # Hacemos todos los ensayos que se necesiten, ni más ni menos
        take = min(can_add, needed_points)
        essays_done += essays * take
        needed_points -= take

        # Cuando llegamos a la meta, paramos
        if(needed_points == 0):
            break

    print(essays_done)
# Si ya cumplía con el promedio, no hacemos ningún ensayo
else:
    print(0)