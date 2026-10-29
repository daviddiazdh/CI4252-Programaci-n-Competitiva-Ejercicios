#include <iostream>
#include <string>
#include <sstream>
#include <tuple>

using namespace std;

// El problema consiste en simplemente aplicar el algoritmo de Euclides extendido,
// se requiere calcular el máximo común divisor para dos números dados y además 
// los coeficientes (x,y) de la ecuación diofántica xA + yB = gcd(A,B) que tiene garantía
// de siempre tener solución por Bezout.
// El algoritmo se apoya en una propiedad sencilla del máximo común divisor, esta es que 
//                   gcd(a,b) = gcd(b, a mod b)
// De esa manera, se puede definir una recursión hasta que se llegue a un caso base.
// El caso base es sumamente sencillo, gcd(a, 0) = a y, además, 
//                   a(1)+ 0(0) = a
// Es decir, la condición de parada es que el segundo valor en gcd sea 0.
// Los coeficientes son sencillos en este caso, x1 = 1 y y1 = 0, pero al subir en la recursión
// los coeficientes se deben actualizar basado en lo siguiente:
// Supongamos que ya tenemos x1 y y1 para gcd(b, a mod b), entonces
//              b * x1 + (a mod b) * y1 = gcd(a, b)
// Por definición de    
//                  a mod b = a - ⌊a/b⌋ * b   
// Sustituyo en la ecuación anterior
//               b * x1 + (a - ⌊a/b⌋ * b ) * y1 = gcd(a, b)
//             a * y1 + b * (x1 - ⌊a/b⌋ * y1) = gcd(a, b)
// De esa forma nos queda que
//    x = y1       y      y = x1 - ⌊a/b⌋ * y1
// Con esto, armamos la recursión y resolvemos el problema como sigue
int gcd(long long a, long long b, long long& x, long long& y) {
    // Caso bases
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    // Llamada recursiva con nuevos valores
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    // Reconstrucción de x e y como fue comentado más arriba
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Parsear entrada
    string line;
    while (getline(cin, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        long long A, B;
        if (ss >> A >> B) {
            long long X, Y;
            long long G = gcd(A, B, X, Y);

            cout << X << " " << Y << " " << G << endl; 
        }
    }

}