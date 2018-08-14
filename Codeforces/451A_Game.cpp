//
// Created by ManuelLoaiza on 01/29/18.
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int resultado = min(m, n);

    if (resultado % 2 == 0) {
        cout << "Malvika" << endl;
    } else {
        cout << "Akshat" << endl;
    }

    return 0;

}
