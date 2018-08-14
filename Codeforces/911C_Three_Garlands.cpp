//
// Created by ManuelLoaiza on 12/28/17.
//
#include <bits/stdc++.h>

using namespace std;

bool posible(int a, int b, int c) {

    if (a == 1 or b == 1 or c == 1) return 1;
    if (a == 3 and b == 3 and c == 3) return 1;
    if (a == 2 and b == 2 or b == 2 and c == 2 or a == 2 and c == 2) return 1;
    if (a == 2 and b == 4 and c == 4 or a == 4 and b == 2 and c == 4 or a == 4 and b == 4 and c == 2) return 1;
    return 0;

}

int main() {

    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    if (posible(k1, k2, k3)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;

}
