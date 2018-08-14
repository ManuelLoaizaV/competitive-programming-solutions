//
// Created by ManuelLoaiza on 01/31/18.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    double resultado = 99999999.0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (1.0 * x / y < resultado) {
            resultado = 1.0 * x / y;
        }
    }

    cout << fixed << setprecision(6) << resultado * m << endl;

}
