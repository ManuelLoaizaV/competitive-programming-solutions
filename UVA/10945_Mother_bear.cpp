//
// Created by manuelloaiza on 01/30/18.
//

#include <bits/stdc++.h>

using namespace std;

bool esPalindromo(string &s) {
    int limite = (s.size()) / 2;
    for (int i = 0; i < limite; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    string s;

    while (getline(cin, s)) {
        if (s == "DONE") break;
        for (int i = 0; i < s.size(); i++) {
            if ('A' <= s[i] and s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            } else {
                if (s[i] == '.' or s[i] == ',' or s[i] == '!' or s[i] == '?' or s[i] == ' ') {
                    s.erase(s.begin() + i);
                    i--;
                }
            }
        }
        if (esPalindromo(s)) {
            cout << "You won't be eaten!" << endl;
        } else {
            cout << "Uh oh.." << endl;
        }
    }
    return 0;
}
