//
// Created by ManuelLoaiza on 02/04/18.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e+7;
long long tree[MAX + 1];

struct FenwickTree {

    void inicializar() {
        for (long long i = 0; i <= MAX; i++) {
            tree[i] = 0;
        }
    }

    long long query(long long i) {

        long long suma = 0;

        while (i > 0) {
            suma += tree[i];
            i -= (i & - i);
        }

        return suma;

    }

    void update(long long i, long long delta) {
        while (i <= MAX) {
            tree[i] += delta;
            i += (i & - i);
        }
    }

} ft;

void solve() {

    ft.inicializar();

    long long n;
    cin >> n;

    long long number[n];

    for (long long i = 0; i < n; i++) {
        cin >> number[i];
    }

    long long resultado = 0;

    for (long long i = n - 1; i >= 0; i--) {
        resultado += ft.query(number[i]);
        ft.update(number[i], 1);
    }

    cout << resultado << endl;

}

int main() {

    int testCases;
    cin >> testCases;

    while (testCases--) {
        solve();
    }

    return 0;
}
