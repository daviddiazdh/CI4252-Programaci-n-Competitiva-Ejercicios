// En esta implementación simplemente usé Programación 
// Dinámica con un dp(i, bal) donde i es la
// el índice de recorrido de la cadena y bal es un
// contador de llaves abiertas que no han sido cerradas
// hasta entonces, también se puede ver como que 
//         bal = count('{') - count('}')
// la posición dp(i, bal) en total representa
// la mínima cantidad de movimientos que hay que hacer para
// alcanzar un estado con balance entre '{' y '}' de bal 
// y habiendo recorrido hasta la iésima posición de la cadena.
// Lógicamente, nuestra respuesta debe estar en dp(n, 0) porque
// si la cadena no llega balanceada, habremos perdido el tiempo,
// además, el enunciado garantiza siempre poder balancear la cadena
// (cantidad par de llaves).
// Como forma de evitar tener que usar una matriz más grande, se usa
// una restricción de expresiones bien parentizadas, el balance nunca
// puede ser negativo, de serlo en algún momento, la cadena no será estable.
// También se sabe que dp(0, 0) = 0 y este será nuestro punto de partida, 
// esta propiedad tiene sentido porque para el string vacío se requieren 0
// movimientos para conseguir un balance de 0.
// La manera de avanzar será simplemente evaluando los dos casos:
//     - ¿Qué ocurre si uso '{' en la posición i?
//     - ¿Qué ocurre si uso '}' en la posición i?
// También se evalúa cuál cuenta como movimiento, puesto que en la cadena ya
// hay una de ellas. Se actualiza la tabla en cada fila y por cada columna
// posible, hasta llenar la última fila, quedándonos con dp[n, 0]

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string case_str;
    int i = 1;
    while (cin >> case_str) {
        // Entradas
        if (case_str.find('-') != string::npos) {
            break;
        }
        int n = case_str.length();
        vector<int> dp(n + 1, INF);
        // Aseguramos dp[0,0] = 0
        dp[0] = 0;

        // No guardamos la matriz entera, sino las filas que se usan.
        // Solo las dos más recientes: dp y next_dp
        for (int row = 0; row < n; ++row) {
            char ch = case_str[row];
            vector<int> next_dp(n + 1, INF);

            for (int bal = 0; bal <= row; ++bal) {
                // No nos interesan los estados no alcanzables
                if (dp[bal] == INF) continue;

                // Caso '{'
                int costo_open = (ch == '{') ? 0 : 1;
                next_dp[bal + 1] = min(next_dp[bal + 1], dp[bal] + costo_open);

                // Caso '}', teniendo cuidado del balance menor que cero
                if (bal > 0) {
                    int costo_close = (ch == '}') ? 0 : 1;
                    next_dp[bal - 1] = min(next_dp[bal - 1], dp[bal] + costo_close);
                }
            }

            dp = move(next_dp);
        }

        cout << i << ". " << dp[0] << "\n";
        i++;
    }

    return 0;
}

// PD: Intenté esta implementación con Python y dio TLE
// Igualmente, la implementación está en ./OtraManera