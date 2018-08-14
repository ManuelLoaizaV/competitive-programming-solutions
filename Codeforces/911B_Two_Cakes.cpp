//
// Created by ManuelLoaiza on 12/28/17.
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, b;
    cin >> n >> a >> b;
    int limite = min(a, b);
    int resultado = 0;

    for (int i = 1; i <= limite; i++) {
        int x = a / i;
        int y = b / i;
        if (x + y >= n) resultado = i;
    }

    cout << resultado << endl;
    return 0;
}
