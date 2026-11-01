#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int main() {

    // En esta lo que hago es comparar las posibles respuestas factibles, 
    // recordando que se debe tomar la suma de elementos de un subconjunto 
    // donde posiblemente algunos de ellos estén multiplicados por k contiguamente. 
    // Surgen solo cuatro tipos de subconjuntos que representan la belleza del arreglo:
    //   - Suconjunto vacío:    
    //                                           []  =>  0  
    //                   (Solo cuando todos los elementos son negativos y también k)
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
    // dp[i][0]: Determina la mejor suma de elementos de un subconjunto hasta i sin multiplicar k.
    // dp[i][1]: Determina la mejor suma de elementos de un subconjunto hasta i finalizando con k * a_i.
    // dp[i][2]: Determina la mejor suma de elementos de un subconjunto hasta i con una sección
    //           multiplicada por k, pero finalizando por a_i 

    // En cada iteración buscamos el mejor y actualizamos un result global 

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

    // Como solo se necesita el actual y el anterior,
    // uso una tabla DP con dos filas
    vector<vector<long long>> dp = {{0LL,0LL,0LL}, 
                                    {0LL,0LL,0LL}};

    long long result = 0;

    int i = 0;
    for(long long val : array){

        int curr = (i + 1) % 2;
        int prev = i % 2;
        
        dp[curr][0] = max(dp[prev][0] + val, 0LL);

        dp[curr][1] = max({dp[prev][1] + k * val, dp[prev][0] + k * val, 0LL});

        dp[curr][2] = max({dp[prev][2] + val, dp[prev][1] + val, 0LL});

        result = max({result, dp[curr][0], dp[curr][1], dp[curr][2]});

        i++; 

    } 

    cout << result << endl; 


}