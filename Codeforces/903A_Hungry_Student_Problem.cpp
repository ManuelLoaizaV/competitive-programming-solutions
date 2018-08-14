//
// Created by ManuelLoaiza on 12/12/17.
//

#include <bits/stdc++.h>

using namespace std;

bool escribir[101];

void calcular() {

    for (int i = 1; i <= 100; ++i) {

        int tres = i / 3;
        int sietes = i / 7;

        for (int j = 0; j <= tres; ++j) {
            if ((i - 3 * j) % 7 == 0) escribir[i] = 1;
        }

        for (int j = 0; j <= sietes; ++j) {
            if ((i - 7 * j) % 3 == 0) escribir[i] = 1;
        }

    }

}

int main() {

    calcular();
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        if (escribir[x]) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
