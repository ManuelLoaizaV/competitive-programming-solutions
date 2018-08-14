//
// Created by manuelloaiza on 23/02/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    int clasroom[m];
    memset(clasroom, 0, sizeof(clasroom));
    for (int i = 0; i < n; i++) {
        cin >> x;
        clasroom[x]++;
    }
    for (int i = 0; i < m; i++) {
        cout << clasroom[i] << " ";
    }
    return 0;
}
