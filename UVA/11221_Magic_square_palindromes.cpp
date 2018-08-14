//
// Created by ManuelLoaiza on 03/20/2018.
//
#include <bits/stdc++.h>

using namespace std;

void cleanString(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'a' or 'z' < s[i]) {
            s.erase(s.begin() + i);
            i--;
        }
    }
}

void solve() {
    string line;
    getline(cin, line);
    cleanString(line);
    int k = line.size();
    int root = sqrt(k);
    if (root * root != k) {
        printf("No magic :(\n");
        return;
    }
    char letters[root][root];
    for (int i = 0; i < root; i++) {
        for (int j = 0; j < root; j++) {
            letters[i][j] = line[i * root + j];
        }
    }
    for (int i = 0; i < root; i++) {
        for (int j = 0; j < root; j++) {
            if (letters[i][j] != letters[root - i - 1][root - j - 1]) {
                printf("No magic :(\n");
                return;
            }
        }
    }
    for (int i = 0; i < root; i++) {
        for (int j = 0; j < root; j++) {
            if (letters[j][i] != letters[root - j - 1][root - i - 1]) {
                printf("No magic :(\n");
                return;
            }
        }
    }
    printf("%d\n", root);
}

int main() {
    int n;
    scanf("%d", &n);
    string aux;
    getline(cin, aux);
    for (int i = 1; i <= n; i++) {
        printf("Case #%d:\n", i);
        solve();
    }
    return 0;
}
