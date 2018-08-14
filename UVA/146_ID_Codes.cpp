//
// Created by ManuelLoaiza on 03/01/18 
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    char code[51];
    while (gets(code)) {
        if (code[0] == '#') break;
        if (next_permutation(code, code + strlen(code))) cout << code << endl;
        else cout << "No Successor" << endl;
    }
    return 0;
}
