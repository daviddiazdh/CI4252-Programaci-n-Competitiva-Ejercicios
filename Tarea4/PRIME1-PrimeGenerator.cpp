#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// Para esta implementación usaremos dos algoritmos diferentes:
// La criba lineal y los conceptos de la criba segmentada para
// trabajar el rango de l a r como si fuera un bucket en la criba
// segmentada. 
// Nos aprovechamos de un teorema bastante útil,
//     En un rango de [2..N] todos los números compuestos tienen
//     al menos un factor primo p tal que p < √N. 
// Este teorema nos permite generar los primos hasta √N y tener total
// certeza de que podremos tachar como falsos a todos los números 
// compuestos hasta N.

// Para ello entonces usamos la criba lineal, vamos a generar todos los 
// primos hasta √r en un arreglo llamado pr. 
// Posteriormente, por cada primo p en pr vamos a primero buscar el primer 
// múltiplo de p en el rango [l, r], este será ⌈l / p⌉ * p, este lo tachamos
// como falso y nos movemos de p en p tachando como falsos los números donde 
// caigamos. 
// Luego, nos aseguramos de que 1 y 0 no se mantengan marcados como primos, 
// los marcamos como falso si pertenecen a [l, r] y eso sería todo.


int main(){
    
    int t;
    cin >> t;

    while(t > 0){

        // Entrada
        long long l, r;
        cin >> l;
        cin >> r;

        // Generamos los primos con criba lineal hasta √r
        long long limit = sqrt(r);

        vector<long long> lp(limit + 1);
        vector<long long> pr = {};

        for (long long i = 2; i <= limit; ++i){
            if(lp[i] == 0){
                lp[i] = i;
                pr.push_back(i);
            }
            for (long long j = 0; i * pr[j] <= limit; ++j){
                lp[i * pr[j]] = pr[j];
                if(pr[j] == lp[i]){
                    break;
                }
            }
        }

        // Utilizamos la idea de criba segmentada para usar un único bucket, [l, r],
        // y marcar como falso a todos los números compuestos múltiplos de estos primos.
        
        // Creamos un bucket del tamaño del rango
        vector<char> isprime(r - l + 1, true);
        for(long long p : pr){
            for(long long j = max(p, (l + p - 1) / p) * p; j <= r; j += p){
                // Resto l porque el bucket está 0-indexado
                isprime[j - l] = false; 
            }
        }
        // Nos aseguramos que 0 y 1 sean falsos si están en el rango [l, r]
        for(long long x = l; x <= min(r, 1LL); x++){
            isprime[x - l] = false;
        }
        
        // Imprimimos los primos del bucket que sean true.
        // index empieza en l porque el bucket está 0 indexado y realmente
        // el 0 representa el número l, el 1 el l + 1 y así sucesivamente
        long long index = l;
        for(char ip : isprime){
            if(ip == true){
                cout << index << endl;
            }
            index++;
        }
        cout << endl;

        t--;
    }

}
