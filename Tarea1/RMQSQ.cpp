#include <iostream>
using namespace std;

const int MAXN = 100000;
int a[MAXN];
int tree[4 * MAXN];

// Función build muy similar a la mostrada en clases,
// crea el Segment Tree.
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);              
    build(2 * node + 1, mid + 1, end);          
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int oo = 1000000000;
// Función query para las consultas al Segment Tree
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return oo;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}

int main(){

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Después de recibir los datos, creamos el Segment Tree
    build(1, 0, n - 1);

    int q;
    cin >> q;

    // Simplemente tomamos los bordes del rango y ejecutamos las queries
    for (int i = 0; i < q; i++) {
        int left, right;
        cin >> left;
        cin >> right;

        cout << query(1, 0, n - 1, left, right) << endl;
    }

    return 0;

}