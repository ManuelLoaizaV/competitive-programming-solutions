//
// Created by ManuelLoaiza on 03/02/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+6;
char answer[MAX_N + 1];
int K, L, m;

void calculate() {
    answer[0] = 'B';
    for (int i = 1; i <= MAX_N; i++) {
        answer[i] = 'B';
        if (i - 1 >= 0 and answer[i - 1] == 'B' or
            i - K >= 0 and answer[i - K] == 'B' or
            i - L >= 0 and answer[i - L] == 'B') answer[i] = 'A';
    }
}

int main() {
    scanf("%d %d %d", &K, &L, &m);
    calculate();
    string output = "";
    int coins;
    while (m--) {
        scanf("%d", &coins);
        output += answer[coins];
    }
    cout << output << endl;
    return 0;
}
