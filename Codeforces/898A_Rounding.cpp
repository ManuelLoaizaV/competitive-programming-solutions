//
// Created by ManuelLoaiza on 12/16/17.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    int resultado = n / 10;
    resultado *= 10;

    int aux = n % 10;

    if (aux >= 5) resultado += 10;

    cout << resultado << endl;

    return 0;
}
