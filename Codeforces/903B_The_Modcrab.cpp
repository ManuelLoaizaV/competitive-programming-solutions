//
// Created by ManuelLoaiza on 12/12/17.
//

#include <bits/stdc++.h>

using namespace std;

int h1, a1, c1, h2, a2;
vector <string> resultado;

void calcular() {

    while (h2 > 0) {

        if (h1 <= a2) {
            if (a1 >= h2) {
                resultado.push_back("STRIKE");
                h2 -= a1;
            } else {
                resultado.push_back("HEAL");
                h1 += c1;
            }
        } else {
            resultado.push_back("STRIKE");
            h2 -= a1;
        }

        if (h2 > 0) h1 -= a2;

    }
}

int main() {

    cin >> h1 >> a1 >> c1 >> h2 >> a2;

    calcular();

    int n = resultado.size();
    cout << n << endl;

    for (int i = 0; i < n; i++) cout << resultado[i] << endl;

    return 0;
}
