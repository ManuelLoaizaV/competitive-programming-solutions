//
// Created by ManuelLoaiza on 03/23/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
const int MAX_LG = (int) log2(MAX_N) + 1;
int ST[MAX_N][MAX_LG];

void precalculate(int a[], int n) {
    for (int i = 0; i < n; i++) ST[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            ST[i][j] = min(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int T = R - L + 1;
    int lg = 31 - __builtin_clz(T);
    return min(ST[L][lg], ST[R - (1 << lg) + 1][lg]);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    precalculate(a, n);
    int answer = query(0, n - 1);
    if (k > 1) {
        if (k == 2) {
            for (int i = 0; i < n - 1; i++) {
                answer = max(answer, max(query(0, i), query(i + 1, n - 1)));
            }
        } else {
            for (int i = 0; i < n; i++) {
                answer = max(answer, a[i]);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}