//
// Created by ManuelLoaiza on 01/30/18.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    bool estado = false;
    string s;

    while (getline(cin, s)) {
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (s[i] == 34) {
                switch (estado) {
                    case false:
                        cout << "``";
                        break;
                    case true :
                        cout << "''";
                        break;
                }
                estado = not estado;
                continue;
            }
            cout << s[i];
        }
        cout << endl;
    }

    return 0;
}
