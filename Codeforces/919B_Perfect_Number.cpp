//
// Created by ManuelLoaiza on 01/31/18.
//

#include <bits/stdc++.h>

using namespace std;

int sumaDigitos(long long n) {

    if (n < 10) return n;
    return n % 10 + sumaDigitos(n / 10);

}

int main() {

    int k;
    cin >> k;

    int cont = 0;
    int resultado = 0;
    long long inicial = 19;

    while (cont < k) {

        if (sumaDigitos(inicial) == 10) {
            cont++;
            resultado = inicial;
        }

        inicial++;

    }

    cout << resultado << endl;

    return 0;
}
