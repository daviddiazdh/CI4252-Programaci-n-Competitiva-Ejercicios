#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// La implementación hecha por la IA utiliza una tabla esparsa
// lo que garantiza que la complejidad del procesamiento a nivel de tiempo
// sea O(n log n), mientras que la implementación con Segment Tree es 
// O(n). Por otro lado, las consultas de la tabla esparsa son todas O(1),
// mientras que las de Segment Tree son O(log n), por lo tanto, los tiempos
// finales serían:
// Tabla esparsa: O(n log n + q)
// Segment Tree: O(n + q log n)
// Esto quiere decir que su implementación es mejor en caso de que no hayan
// tantísimos datos y hayan muchas consultas; mientras que si hay muchos datos
// y pocas consultas, entonces resulta mejor el Segment Tree.
// Como no conocemos los casos de prueba, entonces no hay ninguna solución que
// sea objetivamente mejor, de hecho, si los datos se modificaran (no pasa en
// el enunciado), entonces el Segment Tree es mucho mejor.

// Por lo demás, es una solución bastante sensata.

int main() {

    int n;
    if (!(cin >> n)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }

    int max_log = lg[n] + 1;
    vector<vector<int>> st(max_log, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        st[0][i] = a[i];
    }

    for (int j = 1; j < max_log; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[j][i] = min(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }

    int q;
    if (cin >> q) {
        while (q--) {
            int l, r;
            cin >> l >> r;
            
            if (l > r) swap(l, r);

            int len = r - l + 1;
            int k = lg[len];
            
            int ans = min(st[k][l], st[k][r - (1 << k) + 1]);
            cout << ans << "\n";
        }
    }

    return 0;
}