#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <limits>

using namespace std;

// Utilizo una estrategia greedy total, simplemente
// recorro los valores dados y registro las veces que se repiten en un 
// arreglo estático con índices como llaves. 
// Luego, trato de crear buckets cuyo máximo sea el número actual, por ejemplo: 
// Inicio con 0, por lo tanto, trato de crear un bucket de la forma {0...0} 
// de tamaño k, si no se tienen suficientes 0's, ya sé que el 0 es la respuesta 
// porque no será máximo de su propio bucket.
// Si hay suficientes 0's, en el siguiente, el 1, hago lo mismo, pero considero 
// los 0's sobrantes del bucket anterior, porque puedo rellenar el bucket como
//                          {1,1,1,0,0,...,0}
// con los ceros que quiera. Es decir, para cada valor i que requiere un bucket 
// donde él mismo sea el mayor, puedo aprovechar todos los números menores a i
// sobrantes. 
// Por otro lado, también verifico que las keys en el mapa sean contiguas, 
// si la cantidad de veces que aparece un valor al iterar es 0, entonces él es
// el máximo directamente.


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t > 0){

        int n, k;
        cin >> n;
        cin >> k;

        vector<int> rep(n + 2, 0);
        int max_val = 0;
        int copy_n = n;

        while(copy_n > 0){

            int value;
            cin >> value; 
            rep[value]++; 
            max_val = max(max_val, value);

            copy_n--;
        }


        int min_accums = 0;
        int last = 0;
        for(int i = 0; i <= n + 1; i++){
            int reps = rep[i];

            if(reps + min_accums < k || reps == 0 || i > max_val){
                cout << i << endl;
                break;
            }

            min_accums = reps + min_accums - k;
            last = i;

        }

        t--;
    }

}