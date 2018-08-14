//
// Created by ManuelLoaiza on 12/29/17.
//

#include <bits/stdc++.h>

using namespace std;

string victoria;

struct punto {
    int x;
    int y;
};

void generar(string &s, char a, char b, char c, char d) {

    for (int i = 0; i < victoria.size(); i++) {
        switch (victoria[i]) {
            case '0':
                s = s + a;
                break;
            case '1':
                s = s + b;
                break;
            case '2':
                s = s + c;
                break;
            case '3':
                s = s + d;
                break;
        }
    }

}

int main() {

    int n, m;
    cin >> n >> m;

    string maze[50];
    punto start, exit;

    for (int i = 0; i < n; i++) {

        cin >> maze[i];

        for (int j = 0; j < m; j++) {

            if (maze[i][j] == 'S') {
                start.x = i;
                start.y = j;
            }

            if (maze[i][j] == 'E') {
                exit.x = i;
                exit.y = j;
            }

        }
    }

    cin >> victoria;

    punto direccion[4];
    direccion[0].x = 0;
    direccion[0].y = 1;
    direccion[1].x = 0;
    direccion[1].y = -1;
    direccion[2].x = -1;
    direccion[2].y = 0;
    direccion[3].x = 1;
    direccion[3].y = 0;

    string soluciones[24];

    generar(soluciones[0], '0', '1', '2', '3');
    generar(soluciones[1], '0', '1', '3', '2');
    generar(soluciones[2], '0', '2', '1', '3');
    generar(soluciones[3], '0', '2', '3', '1');
    generar(soluciones[4], '0', '3', '1', '2');
    generar(soluciones[5], '0', '3', '2', '1');
    generar(soluciones[6], '1', '0', '2', '3');
    generar(soluciones[7], '1', '0', '3', '2');
    generar(soluciones[8], '1', '2', '0', '3');
    generar(soluciones[9], '1', '2', '3', '0');
    generar(soluciones[10], '1', '3', '0', '2');
    generar(soluciones[11], '1', '3', '2', '0');
    generar(soluciones[12], '2', '0', '1', '3');
    generar(soluciones[13], '2', '0', '3', '1');
    generar(soluciones[14], '2', '1', '0', '3');
    generar(soluciones[15], '2', '1', '3', '0');
    generar(soluciones[16], '2', '3', '0', '1');
    generar(soluciones[17], '2', '3', '1', '0');
    generar(soluciones[18], '3', '0', '1', '2');
    generar(soluciones[19], '3', '0', '2', '1');
    generar(soluciones[20], '3', '1', '0', '2');
    generar(soluciones[21], '3', '1', '2', '0');
    generar(soluciones[22], '3', '2', '0', '1');
    generar(soluciones[23], '3', '2', '1', '0');

    int resultado = 0;

    for (int i = 0; i < 24; i ++) {

        punto posicionActual = start;
        int l = soluciones[i].size();

        for (int j = 0; j < l; j++) {

            posicionActual.x = posicionActual.x + direccion[soluciones[i][j] - '0'].x;
            posicionActual.y = posicionActual.y + direccion[soluciones[i][j] - '0'].y;

            if (posicionActual.x == exit.x and posicionActual.y == exit.y) {
                resultado++;
                break;
            }

            if (posicionActual.x < 0 or posicionActual.x >= n or posicionActual.y < 0 or posicionActual.y >= m) {
                break;
            }

            if (maze[posicionActual.x][posicionActual.y] == '#') {
                break;
            }

        }

    }

    cout << resultado << endl;

    return 0;
}
