//
// Created by ManuelLoaiza on 01/29/18.
//

#include <bits/stdc++.h>

using namespace std;

string aMayusculas(string &s) {

    for (int i = 0; i < s.size(); i++) {
        s[i] = toupper(s[i]);
    }

    return s;

}

string aMinusculas(string &s) {

    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    return s;

}

int main() {

    string palabra;
    cin >> palabra;

    int mayusculas = 0, minusculas = 0;

    for (int i = 0; i < palabra.size(); i++) {

        if ('a' <= palabra[i] and palabra[i] <= 'z') {
            minusculas++;
        } else {
            mayusculas++;
        }

    }

    string resultado = "";

    if (mayusculas > minusculas) {
        resultado += aMayusculas(palabra);
    } else {
        resultado += aMinusculas(palabra);
    }

    cout << resultado << endl;

    return 0;
}
