#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {

    // En esta lo que hago es comparar las posibles respuestas factibles, 
    // recordando que se debe tomar la suma de elementos de un subconjunto 
    // donde posiblemente algunos de ellos estén multiplicados por k contiguamente. 
    // Surgen solo cuatro tipos de subconjuntos respuesta:
    //   - Suconjunto vacío:    
    //                                           []  =>  0  
    //                 (Solo cuando todos los elementos negativos y también k)
    //   - Subconjuntos sin k:  
    //                      [a_1, a_2, ..., a_r]  =>  a_1 + a_2 + ... + a_r
    //   - Subconjuntos que terminan con elementos multiplicados por k:
    //               [a_1, a_2, ..., ka_(r-1), ka_r] =>  a_1 + a_2 + ... + k(a_(r-1) + a_r)
    //   - Subonjuntos que tienen elementos multiplicados por k, pero no terminan con ellos:
    //               [a_1, a_2, ... , ka_(l-1), ka_l , ... , a_(r-1), a_r] 
    // Estos son todos los posibles tipos de soluciones.
    // Lo que hago es un algoritmo con DP Bottom-Up que determina cuál es la mejor de estas
    // opciones hasta un valor i del arreglo.

    // Para un valor intermedio i dado, definimos tres estados para la DP.
    // (dp_no_k)_i: Determina la mejor suma de elementos de un subconjunto hasta i sin k,
    //              escoge lo mejor entre agregar a_i o no.
    // (dp_end_k)_i: Determina la mejor suma de elementos de un subconjunto hasta i
    //               comparando la anterior y la que finaliza con k * a_i.
    // (dp_after_k)_i: Determina la mejor suma de elementos de un subconjunto hasta i
    //                 comparando la anterior (potencialmente con k) y la que finaliza con a_i. 

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long k;
    cin >> k;
    
    vector<long long> array;

    while(n > 0){
        
        long long val;
        cin >> val;

        array.push_back(val);

        n--;
    }

    vector<vector<long long>> dp = {{0LL,0LL,0LL}, 
                                    {0LL,0LL,0LL}};

    int i = 0LL;
    for(long long val : array){

        // Si es mejor 0 que la suma de elementos hasta entonces, 
        // mejor se queda con 0

        dp[(i + 1) % 2][0] = max(dp[i][0] + val, 0LL);

        dp[(i + 1) % 2][1] = max(dp[i][1] + k * val, 0LL);

        dp[(i + 1) % 2][2] = max(dp[i][2] + val, dp[(i + 1) % 2][1]);

        i = (i + 1) % 2; 

    } 

    cout <<  dp[(i + 1) % 2][2] << endl; 



}