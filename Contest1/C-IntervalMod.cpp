#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Si analizamos el problema sin la restricción de la ventana,
// es fácil ver que si quiero el mínimo de cada valor del arreglo
// debo comparar qué pasa al usar p y al usar q, como p < q,
// puede ser que usando "% q" no tengamos el mínimo, el valor podría
// quedarse en esta zona:
//                         [aquí]
//        --------------|------------|
//                      p            q
// Aplicando a ese valor "% p" lo haríamos más pequeño (mínimo).
// Por lo que el mínimo de a_i sería uno de dos, o bien a_i % p; 
// o bien (a_i % q) % p. Entonces, para cada a_i, escojo el mínimo.

// Ahora considerando las ventanas de tamaño k, a toda la ventana
// (a cada valor) se le debe aplicar un mismo módulo, pero pongámonos
// en la situación de que ya se aplicó un módulo en una ventana de tamaño k,
//                             -------- k --------
//            a0 ... ai a(i+1) [a_(l) ... a(l + k)] a(l + k + 1) ... a(n-1)
// cada elemento en la ventana tendrá un módulo, o bien a % p; o bien (a % q) % p
// (aplicando el módulo 2 veces en la misma ventana). Como ahora cualquier módulo 
// que aplique sobre la ventana no cambia los valores, 
//         a % p % p = a % p                 a % p % q = a % p
//     (a % q) % p % p = (a % q) % p      (a % q) % p % q = (a % q) % p
// entonces si quiero minimizar a(i+1), simplemente tomo el módulo que más le conviene 
// a a(i+1) y se lo aplico a una venta que va desde a(i+1) hasta a(l+k), obteniendo
// el valor mínimo posible en a(i+1). Obivamente, esto aplica a todos los demás valores 
// fuera de la ventana. Así que puedo minimizar lo mejor posible todos los valores fuera
// de la ventana, por lo tanto, lo que me queda es considerar el valor de cada ventana 
// con su mejor operador y sumarle los mínimos de todos los valores fuera de ella.
// Para ello uso suma de prefiijos, de modo que la suma de un operador 'op' sobre una ventana
// de r - k a r sería
//                         strategy_mod[op][r] - strategy_mod[0][r - k]
// Y el resto sería considerar el arreglo de prefijos para los mínimos posibles tanto de los 
// que quedan a la izquierda de la ventana, como los de la derecha.
// Comparamos todas las ventanas y nos quedamos con la mejor.

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t > 0){
        
        int n, k;
        long long p, q;
        cin >> n;
        cin >> k;
        cin >> p;
        cin >> q;

        vector<long long> a;

        for(int i = 0; i < n; i++){
            long long val;
            cin >> val;
            a.push_back(val);
        }

        vector<vector<long long>> strategy_mod(2, vector<long long>(n, 0));

        vector<long long> each_min(n);

        long long optimal_sum = 0;

        int index = 0;
        for(long long x : a){
            
            // Guardo ambos posibles módulos para cada valor
            strategy_mod[0][index] = x % p;
            strategy_mod[1][index] = (x % q) % p;

            // Guardo el mínimo de cada valor
            each_min[index] = min(strategy_mod[0][index], strategy_mod[1][index]);

            index++;
        }

        // Hacemos que strategy_mod y each_min sean arreglos de prefijos
        for(int i = 1; i < n; i++){
            strategy_mod[0][i] += strategy_mod[0][i-1];
            strategy_mod[1][i] += strategy_mod[1][i-1];
            each_min[i] += each_min[i-1];
        }


        long long optimal_result = numeric_limits<long long>::max();
        // Por último, recorro cada una de las ventanas y me quedo con la mejor
        for(int i = k - 1; i < n; i++){
            long long left  = (i - k >= 0) ? each_min[i - k] : 0;
            long long window_val_strategy_0 = strategy_mod[0][i] - (i - k >= 0 ? strategy_mod[0][i - k] : 0);
            long long window_val_strategy_1 = strategy_mod[1][i] - (i - k >= 0 ? strategy_mod[1][i - k] : 0);
            long long right = each_min[n - 1] - each_min[i];

            long long possible_optimal = left + min(window_val_strategy_0, window_val_strategy_1) + right;
            
            if(possible_optimal < optimal_result){
                optimal_result = possible_optimal;
            }
            
        }

        cout << optimal_result << "\n";
        t--;

    }

}