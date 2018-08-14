//
// Created by ManuelLoaiza on 12/29/17
//

#include <bits/stdc++.h>

using namespace std;

bool vocal(char a) {
    if (a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u') return 1;
    return 0;
}

bool impar(char a) {
    if (a == '1' or a == '3' or a == '5' or a == '7' or a == '9') return 1;
    return 0;
}

int main() {

    string s;
    cin >> s;
    int n = s.size();
    int resultado = 0;

    for (int i = 0; i < n; i++) {
        if (vocal(s[i]) or impar(s[i])) resultado++;
    }

    cout << resultado << endl;

    return 0;
}
