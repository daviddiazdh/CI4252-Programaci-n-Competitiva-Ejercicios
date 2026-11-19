#include <iostream>
#include <string>
#include <sstream>
#include <complex>
#include <vector>

using namespace std;

// Hice la implementación basada en CP Algorithms como base, 
// pero la lógica del código es la expuesta por Moni en sus clases de 
// Diseño de Algoritmos I, la diferencia radica en detalles como evitar
// la inclusión del parámetro inverted como booleano y, en vez de eso,
// mandar el número complejo w base como argumento.

const double PI = acos(-1);

void fft(vector<complex<double>> & a, complex<double> wn) {
    long long n = a.size();
    // Caso base
    if (n == 1) return;

    // Hacemos el arreglo de coeficientes pares e impares
    vector<complex<double>> a0(n / 2), a1(n / 2);
    for (long long i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }

    // Llamamos a FFT para cada uno pero mandando como nueva base a w^2,
    // esto hace que el problema ahora trabaje en una potencia de w^p = 1
    // menor que la actual, con la garantía de siempre tener un w y su negativo
    fft(a0, wn * wn);
    fft(a1, wn * wn);

    // Construimos el vector a de respuesta que es una representación puntual 
    // única del vector, con puntual nos referimos a que se representa con
    // los reflejos del polinomio en cada uno de las n diferentes soluciones de w^n = 1 
    complex<double> w(1);
    for (long long i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        w *= wn;
    }
}


vector<long long> multiply(vector<long long> const& a, vector<long long> const& b) {
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    long long n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;

    // Hacemos que los vectores de coeficientes se rellenen con ceros para incluir 
    // los hasta 2n coeficientes posibles de la multiplicación
    fa.resize(n);
    fb.resize(n);

    // Calculamos el w base del cual calculamos todos los demás
    double ang = 2 * PI / n;
    complex<double> w(cos(ang), sin(ang));

    // Llamamos a los dos FFT y multiplicamos para crear el vector de representación
    // puntual del polinomio
    fft(fa, w);
    fft(fb, w);
    for (long long i = 0; i < n; i++)
        fa[i] *= fb[i];

    // Como la representación es la puntual y queremos la de coeficientes, volvemos a 
    // calcular una FFT, pero sabiendo que esta recibe w^(-1) como argumento y 
    // se divide cada elemento por n, es importante destacar que esto viene de las matrices
    // de Vandermonde y la forma final de la matriz inversa
    complex<double> w_inv = complex<double>(1) / w;
    fft(fa, w_inv);
    vector<long long> result(n);
    for (long long i = 0; i < n; i++)
        result[i] = round(fa[i].real() / n);
    return result;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Casos totales
    int t;
    cin >> t;
    while(t > 0){

        // Grado de los polinomios
        long long n;
        cin >> n;
        long long copy_n = n;
        vector<long long> p1(n + 1);
        // Polinomio 1
        while(copy_n >= 0){
            long long num;
            cin >> num;
            p1[copy_n] = num;
            copy_n--;
        }

        // Polinomio 2
        copy_n = n;
        vector<long long> p2(n + 1);
        while(copy_n >= 0){
            long long num;
            cin >> num;
            p2[copy_n] = num;
            copy_n--;
        }

        // Obtenemos su multiplicación
        vector<long long> result = multiply(p1, p2);

        // Quitamos los ceros que no son significativos, 
        // los que fueron agregados para que el tamaño fuera 
        // una potencia de dos (ceros a la izquierda)
        long long m = result.size();
        bool first_non_zero = false;
        for(long long i = m - 1; i >= 0; i--){
            if(!first_non_zero && result[i] == 0){
                continue;
            } else{
                first_non_zero = true;
                cout << result[i] << " "; 
            }
        }
        cout << endl;

        t--;
    } 
}

