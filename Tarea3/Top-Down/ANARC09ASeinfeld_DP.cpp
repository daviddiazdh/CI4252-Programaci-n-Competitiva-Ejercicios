// Misma implementación que en la Bottom-Up, pero con uso de 
// recursión partiendo del caso específico a los casos bases
// evitando el cálculo de estados ya antes calculados,
// mismo concepto que la caché.   
// La recursión simplemente se pregunta qué ocurre en los dos
// posibles casos de cada índice: 
//      - Colocar/Dejar '{'
//      - Colocar/Dejar '}'
// recorre cada caso sobre el árbol de decisiones como un DFS
// y como hay estados repetidos otras ramas, los saca de la
// memoria en vez de recalcular. Siempre se queda con el camino
// de menor cantidad de instrucciones.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int memo[2005][2005];
string case_str;
int n;

int solve(int i, int bal){
    // Caso base
    if (i == n) return (bal == 0) ? 0 : INF;
    
    // Si ese estado ya se recorrió en memoria, se aprovecha
    if (memo[i][bal] != -1) return memo[i][bal];

    // Desarrolla la rama hasta el caso base cuando usamos '{'
    int op1 = (case_str[i] == '{' ? 0 : 1) + solve(i + 1, bal + 1);
    int op2 = INF;
    // Desarrolla la rama hasta el caso base cuando usamos '}', si se puede
    if (bal > 0) op2 = (case_str[i] == '}' ? 0 : 1) + solve(i + 1, bal - 1);

    // Nos quedamos con el mejor
    return memo[i][bal] = min(op1, op2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Entradas
    int i = 1;
    while (cin >> case_str) {
        if (case_str.find('-') != string::npos) {
            break;
        }

        n = case_str.length();
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                memo[i][j] = -1;
            }
        }

        // Llamada simple a la función recursiva en forma Top-Down
        cout << i << ". " << solve(0, 0) << "\n";
        i++;
    }

    return 0;
}


