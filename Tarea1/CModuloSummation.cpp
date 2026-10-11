#include <bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Lo primero que analicé es el módulo óptimo para cada uno de los x's
    // dados, para a y b dados, los módulos más altos que pueden
    // conseguir ambos es a - 1 y b -1 respectivamente. 
    // Ahora bien, se puede conseguir que ambos módulos sean máximos usando 
    // el mcm(a, b) - 1, porque cuando se evalúe (mcm(a,b) - 1) mod a va a ser
    // a - 1, mientras que (mcm(a,b) - 1) mod b será b - 1, probando así que 
    // existe un número que consigue esto.
    // Para casos con más números se generaliza sin ningún problema, digamos
    // que tenemos x_1, ..., x_n números positivos, entonces el máximo valor
    // para (k mod x_1) + (k mod x_2) + ... + (k mod x_n) es 
    // x_1 - 1 + x_2 - 1 + ... + x_n - 1 = (x_1 + x_2 + ... + x_n) - n y se 
    // consigue usando k = mcm(x_1, x_2, ..., x_n) - 1, que es un número con
    // garantías de existir. 
    // Finalmente, usé esta prueba para poder entonces resolver el algoritmo
    // en tiempo O(n)

    int n, accum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // Construimos (x_1 + x_2 + ... + x_n)
        accum += x;
    }

    // Imprimimos (x_1 + x_2 + ... + x_n) - n
    cout << accum - n;
}