//
// Created by ManuelLoaiza on 12/28/17.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    int numeros[n];

    for (int i = 0; i < n; i++) {
        cin >> numeros[i];
    }

    int minimo = numeros[0];

    for (int i = 0; i < n; i++) {
        minimo = min(numeros[i], minimo);
    }

    bool primeraVez = 1;
    int posicionAnterior = 0;
    int minimaDistancia = 1e+5;

    for (int i = 0; i < n; i++) {
        if (numeros[i] == minimo) {
            if (primeraVez) {
                posicionAnterior = i;
                primeraVez = 0;
            } else {
                minimaDistancia = min(minimaDistancia, i - posicionAnterior);
                posicionAnterior = i;
            }
        }
    }

    cout << minimaDistancia << endl;

    return 0;
}
