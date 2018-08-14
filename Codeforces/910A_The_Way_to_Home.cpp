//
// Created by ManuelLoaiza on 12/27/17.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, d;
    cin >> n >> d;
    string posiciones;
    cin >> posiciones;
    posiciones = '0' + posiciones;
    int resultado = 0;
    int posicionActual = 1;

    while (1) {

        int posicionAnterior = posicionActual;
        int limiteDerecho = min(posicionActual + d, n);

        for (int i = limiteDerecho; i > posicionActual; i--) {
            if (posiciones[i] == '1') {
                posicionActual = i;
                resultado++;
                break;
            }
        }

        if (posicionAnterior == posicionActual) {
            cout << "-1" << endl;
            break;
        }

        if (posicionActual == n) {
            cout << resultado << endl;
            break;
        }

    }

    return 0;
}
