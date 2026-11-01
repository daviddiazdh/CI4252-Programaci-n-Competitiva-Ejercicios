#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    long long m;
    cin >> n;
    cin >> m;

    int copy_n = n;

    vector<long long> a;

    while(copy_n > 0){

        long long new_value;
        cin >> new_value;

        a.push_back(new_value);

        copy_n--;
    }

    // Si dos elementos son equivalentes en módulo m, es decir, 
    // a[i] ≡ a[j] (mod m), entonces se tiene |a[i] - a[j]| ≡ 0 (mod m).
    // Esto provocaría que toda la multiplicación sea 0. 
    // Como se tienen m diferentes representaciones en aritmética modular de m, por 
    // el principio del palomar, si n > m, al menos dos elementos a[i] y a[j] serán
    // equivalentes módulo m, así que la multiplicación completa daría 0.
    if(n > m){
        cout << 0 << endl; 
        return 0;
    }

    int i = 0;
    long long accum = 1;
    while(i < n){
        int j = i + 1;
        while(j < n){
            accum = (accum * abs(a[i] - a[j])) % m;
            j++;
        }
        i++;
    }

    cout << accum << endl;

}