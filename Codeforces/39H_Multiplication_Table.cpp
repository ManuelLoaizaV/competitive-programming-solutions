//
// Created by ManuelLoaiza on 01/31/18.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;
int k;
int tabla[MAX][MAX];
char digitos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

string cambiarBase(int aux) {

    string resultado = "";

    while (aux >= k) {
        resultado = digitos[aux % k]+ resultado;
        aux = aux / k;
    }

    resultado = digitos[aux] + resultado;
    return resultado;

}

void calcular() {

    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - 1; j++) {
            if (i == 0) {
                tabla[i][j] = j + 1;
            } else {
                tabla[i][j] = tabla[i - 1][j] + j + 1;
            }
        }
    }

}

int main() {

    cin >> k;

    calcular();

    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - 1; j++) {
            cout << cambiarBase(tabla[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;

}
