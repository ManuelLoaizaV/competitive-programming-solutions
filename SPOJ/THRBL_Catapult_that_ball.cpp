//
// Created by ManuelLoaiza on 03/19/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 5e+4;
int ST[MAX_N][17];

void precalculate(int A[], int n) {
    for (int i = 0; i < n; i++) {
        ST[i][0] = A[i];
    }
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    if (R < L) return 0;
    int T = R - L + 1;
    int lg = 31 - __builtin_clz(T);
    return max(ST[L][lg], ST[R - (1 << lg)][lg]);
}

int main() {
    int N, M;
    int city[MAX_N];
    while (scanf("%d %d", &N, &M) == 2) {
        for (int i = 0; i < N; i++) scanf("%d", &city[i]);
        precalculate(city, N);
        int L, R, answer = 0;
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &L, &R);
            R -= 2;
            if (city[L - 1] >= query(L, R)) answer++;
        }
        printf("%d\n", answer);
    }
    return 0;
}
