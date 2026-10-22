# Para esta implementación, se nos pide usar estrategia Greedy
# La estrategia será la siguiente: 
#   - Descartamos todas aquellas subcadenas que ya son estables,
#     esto lo logramos eliminando las subcadenas '{}' todas las
#     las veces que sea posible.
#   - Luego de esto, es claro que lo que quedará en la subcadena
#     restante son simplemente las llaves que entran en conflicto.
#     Estas llaves conflictivas pueden tener simplemente tres tipos:
#     '{{', '}}' o '}{', las primeras dos se corrigen simplemente
#     con 1 movimiento, mientras que la tercera se corrige con 2 
#     movimientos. De esa manera, las escogemos de dos en dos desde
#     el final al principio (puede ser al revés) y las resolvemos 
#     hasta que no queden conflictos.
# Es claro que esta estrategia nos permite conservar todas las llaves
# que ya se encuentran balanceadas y solo concentrarnos en aquellas
# que evitan la estabilidad de la frase. 
# Por otro lado, es óptimo tomar las frases de dos en dos por la 
# estructura de la subcadena de llaves conflictivas, por ejemplo,
# de tener una llave de tipo '{' en esta subcadena, es claro que 
# ella debe tener a su lado una de tipo '{', porque de tener '}'
# no estuviera en la subcadena conflictiva, así que la única manera
# de resolverla es voltear la segunda '{' a '}'. 
# Un caso parecido ocurre con una ocurrencia de '}', esta puede tener
# a su lado cualquiera de las otras dos llaves, para cada una ocurre
# algo distinto:
#   Si a su lado derecho está '}', es análogo al caso anterior.
#   Si a su lado derecho está '{', entonces necesariamente va a tener
#   que resolverse volteando ambas, no puede existir una llave '}' con
#   la que se pueda resolver en un paso más adelante porque no aparecería
#   en la subcadena conflictiva.


# Recibimos la entrada
cases =[]
while True:
    case = input().strip()
    if "-" in case:
        break
    else:
        cases.append(case)


for i, case in enumerate(cases):

    case_stack = []
    for c in case:
        if(len(case_stack) == 0):
            case_stack.append(c)
        else:
            # Eliminamos subcadenas de tipo '{}' para 
            # dejar en la pila nada más que la subcadena conflictiva
            if(c == '}' and case_stack[-1] == '{'):
                case_stack.pop()
            else:
                case_stack.append(c)

    ops = 0
    # Si no hay conflictos, nos vamos
    if(len(case_stack) == 0):
        print(f"{i + 1}. {ops}")
    # Si los hay,
    else:
        # Separamos los casos y contamos la
        # cantidad de operaciones en total para
        # resolverlos
        while(len(case_stack) != 0):
            r = case_stack.pop()
            l = case_stack.pop()

            if(l == '{' and r == '{'):
                ops += 1
            elif(l == '}' and r == '}'):
                ops += 1
            else:
                ops += 2

        print(f"{i + 1}. {ops}")