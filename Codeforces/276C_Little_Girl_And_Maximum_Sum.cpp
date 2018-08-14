//
// Created by ManuelLoaiza on 02/05/18.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e+5;
long long number[MAX + 1];
int frecuencia[MAX + 1];
int acumulado[MAX + 1];

int main() {

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> number[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        frecuencia[l]++;

        if (r < n) {
            frecuencia[r + 1]--;
        }
    }

    for (int i = 1; i <= n; i++) {
        acumulado[i] = frecuencia[i] + acumulado[i - 1];
    }

    sort(acumulado, acumulado + n + 1);
    sort(number, number + n + 1);

    long long resultado = 0;

    for (int i = 0; i <= n; i++) {
        resultado += (acumulado[i] * number[i]);
    }

    cout << resultado << endl;

    return 0;
}
