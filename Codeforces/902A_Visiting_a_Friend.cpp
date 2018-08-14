//
// Created by manuelloaiza on 12/19/17.
//
#include <bits/stdc++.h>

using namespace std;

bool resultado[100];

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        for (int j = x; j < y; j++) {
            resultado[j] = 1;
        }
    }

    bool escribir = 1;

    for (int i = 0; i < m; i++) {
        if (resultado[i] == 0) {
            escribir = 0;
            break;
        }
    }

    if (escribir) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
