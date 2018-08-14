//
// Created by ManuelLoaiza on 01/31/18.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    double a, b, c;
    cin >> a >> b >> c;

    double mayor = (- b + sqrt(b * b - 4 * a * c)) / (2 * a);
    double menor = (- b - sqrt(b * b - 4 * a * c)) / (2 * a);

    cout << setprecision(15) << fixed << max(mayor, menor) << endl << min(mayor, menor) << endl;

    return 0;
}
