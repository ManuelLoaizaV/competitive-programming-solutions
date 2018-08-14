//
// Created by ManuelLoaiza on 03/01/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_INDEX = 60;
long long answer[MAX_INDEX + 1];
long long combinations[MAX_INDEX + 1][MAX_INDEX + 1];
bool calculated[MAX_INDEX + 1][MAX_INDEX + 1];

long long nCr(int n, int r) {
    if (n == r or r == 0) return 1;
    if (r == 1) return n;
    if (calculated[n][r]) return combinations[n][r];
    calculated[n][r] = true;
    combinations[n][r] = nCr(n - 1, r) + nCr(n - 1, r - 1);
    return combinations[n][r];
}

void calculate() {
    answer[0] = 0;
    answer[1] = answer[2] = 1;
    for (int i = 3; i<= MAX_INDEX; i++) {
        answer[i] = answer[i - 1];
        if (i % 2 == 0) answer[i] += nCr(i - 1, i / 2);
    }
}

int main() {
    calculate();
    int t;
    scanf("%d", &t);
    long long n;
    int index;
    while (t--) {
        scanf("%lld", &n);
        index = log2(n);
        printf("%lld\n", answer[index]);
    }
    return 0;
}
