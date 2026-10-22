# Este ejercicio lo resolví simplemente usando una estrategia greedy.
# La idea es simplemente cambiar los dígitos de izquierda a derecha por el valor más
# pequeño que se puede cambiar. Obviamente, el primer dígito no se puede cambiar por 0, 
# así que tendría que cambiarse por 1, en caso de que el dígito ya fuera mínimo, entonces
# no se hace ningún cambio, es decir, no cuenta como uno de los k cambios posibles. Para 
# el resto de dígitos, se cambian por 0 bajo la misma condición de que si ya era 0,
# entonces no cuenta como un cambio.

# Entradas
entry = list(map(int, input().split()))
n = entry[0]
k = entry[1]
number_str = input()

# Variables útiles para la iteración
index = 0
first = True
iter = 0
number_list = list(number_str)

# Caso cuando el número tiene un solo dígito, en dicho caso,
# el menor número sin leading zeroes es 0
if(len(number_list) == 1 and k != 0):
    print(0)

# Caso en el que se deben hacer 0 cambios, devolvemos el número tal cual
elif(k == 0):
    print(number_str)

# Resto de casos
else:
    # Iteramos por el número sin convertirlo a entero, lo manejamos como
    # un string, eso ayuda a no malgastar tiempo en conversiones.
    # Hacemos la estrategia mencionada antes, si es el primer dígito, se cambia
    # por 1, si es otro, por cero. Si ya eran el mínimo, no se cambia nada 
    # y no cuenta para k 
    for i in number_list:
        if i == '0':
            index += 1
            continue

        if first:
            min = '1'
            first = False
        else: 
            min = '0'

        if(i != min):
            number_list[index] = min

            if(iter == k - 1):
                break

            iter += 1
        index += 1

    # También se saca como string para ahorrar tiempo
    output_number = "".join(number_list)

    print(output_number)