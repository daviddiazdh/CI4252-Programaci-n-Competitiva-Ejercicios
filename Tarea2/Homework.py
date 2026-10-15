# Utilicé una estrategia greedy, la idea es simplemente recolectar 
# la cantidad de letras distintas en el string para luego ordenar estos 
# datos de menor a mayor en cantidad de apariciones de dicha letra. 
# Resulta evidente que las letras que nos conviene remover son aquellas 
# que tengan menor frecuencia de aparición, pues agotan en menor medida el
# límite k. Quitamos todas las letras que podamos y luego devolvemos el 
# string sin dichas letras removidas. 

from collections import defaultdict

string = input()
k = int(input())

# Si se puede remover el string completo, imprimimos 0 y ""
if len(string) <= k:
    print(0)
    print("")

# si no, hacemos la estrategia greedy
else:
    # Creamos un diccionario de conteo de letras y otro para anotar
    # la cantidad de letras baneadas del string original
    letters_array = defaultdict(int)
    black_list = defaultdict(int)

    # Contamos las  letras distintas
    for c in string:
        letters_array[c] += 1

    # Las ordenamos de menor a mayor por la estrategia greedy
    sorted_letters = sorted(letters_array.items(), key = lambda x : x[1])
    # Calculamos la cantidad de letras distintas
    distinct_letters = len(sorted_letters)

    # Quitamos todas las repeticiones de cada letra (si nos deja) hasta 
    # agotar k (si se agota toalmente), y las registramos como letras baneadas
    for char, frecuency in sorted_letters:
        if(k < frecuency):
            break
        k -= frecuency
        distinct_letters -= 1
        black_list[char] = frecuency

    # Imprimos la cantidad de letras distintas originales, menos las que quitamos
    print(distinct_letters)

    # Quitamos las letras baneadas del string
    for c in string:
        if(not(black_list) or black_list[c] == 0):
            print(c, end="")
        else:
            black_list[c] -= 1

    print("")