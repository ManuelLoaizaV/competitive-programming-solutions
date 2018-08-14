//
// Created by ManuelLoaiza on 01/30/18.
//

#include <bits/stdc++.h>

using namespace std;

const int vertices = 5;
int solucion[9];
bool arista[vertices][vertices];
bool usado[vertices][vertices];
int contador;

void imprimir() {
    for (int i = 0; i < 9; i++) {
        cout << solucion[i] + 1;
    }
    cout << endl;
}

void backtracking() {
    if (contador == 8) {
        imprimir();
        return;
    }

    for (int i = 0; i < 5; i++) {
        if (arista[solucion[contador]][i] and not usado[solucion[contador]][i]) {
            usado[solucion[contador]][i] = 1;
            usado[i][solucion[contador]] = 1;
            contador++;
            solucion[contador] = i;
            backtracking();
            contador--;
            usado[solucion[contador]][i] = 0;
            usado[i][solucion[contador]] = 0;
        }
    }
}

int main() {
    arista[0][1] = arista[0][2] = arista[0][4] = 1;
    arista[1][0] = arista[1][2] = arista[1][4] = 1;
    arista[2][0] = arista[2][1] = arista[2][3] = arista[2][4] = 1;
    arista[3][2] = arista[3][4] = 1;
    arista[4][0] = arista[4][1] = arista[4][2] = arista[4][3] = 1;
    backtracking();
    return 0;
}
