// Esta es una estrategia Bottom-Up que pensé que era
// Top-Down, pero simplemente es un Bottom-Up yendo de
// el case específico a los casos bases, recorro la 
// la matriz de abajo para arriba, en vez de arriba para
// abajo.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string case_str;
    int i = 1;

    while (cin >> case_str) {
        if (case_str.find('-') != string::npos) {
            break;
        }

        int n = case_str.length();
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int row = n; row > 0; --row) {
            char ch = case_str[row - 1];
            vector<int> next_dp(n + 1, INF);

            for (int bal = 0; bal <= row; ++bal) {
                if (dp[bal] == INF) continue;

                if (bal > 0) {
                    int costo_open = (ch == '{') ? 0 : 1;
                    next_dp[bal - 1] = min(next_dp[bal - 1], dp[bal] + costo_open);
                }
                
                int costo_close = (ch == '}') ? 0 : 1;
                next_dp[bal + 1] = min(next_dp[bal + 1], dp[bal] + costo_close);
                
            }

            // cout << "Fila " << row << endl;

            // for(int i : next_dp){
            //     cout << i << " ";
            // }
            // cout << "\n";

            // for(int i : dp){
            //     cout << i << " ";
            // }
            // cout << "\n";

            dp = move(next_dp);
        }

        cout << i << ". " << dp[0] << "\n";
        i++;
    }

    return 0;
}