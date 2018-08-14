//
// Created by ManuelLoaiza on 12/29/17.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;
long long x[MAX];
long double y[MAX];

int main() {

    long long n, r;
    cin >> n >> r;


    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            long long d = abs(x[i] - x[j]);

            if (d <= 2 * r) {
                long double yAux = y[j] + sqrt(4.0 * r * r - d * d);
                y[i] = max(y[i], yAux);
            }

        }

        if (y[i] == 0) {
            y[i] = r;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << setprecision(12) << y[i];
        if (i < n -1) cout << " ";
    }

    return 0;
}
