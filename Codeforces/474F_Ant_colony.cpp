//
// Created by ManuelLoaiza on 03/22/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
int ST[MAX_N][18];
map<int, vector<int> > positions;
map<int, vector<int> >::iterator it;

void precalculate(int s[], int n) {
    for (int i = 0; i < n; i++) ST[i][0] = s[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            ST[i][j] = __gcd(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int T = R - L + 1;
    int lg = 31 - __builtin_clz(T);
    return __gcd(ST[L][lg], ST[R - (1 << lg) + 1][lg]);
}

int occurrences(int gcd, int L, int R) {
    it = positions.find(gcd);
    if (it == positions.end()) return 0;
    vector<int>::iterator low, up;
    low = lower_bound(positions[gcd].begin(), positions[gcd].end(), L);
    up = upper_bound(positions[gcd].begin(), positions[gcd].end(), R);
    return up - low;
}

int main() {
    int n;
    scanf("%d", &n);
    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
        it = positions.find(s[i]);
        if (it == positions.end()) positions[s[i]];
        positions[s[i]].push_back(i);
    }
    precalculate(s, n);

    int q, L, R, gcd, answer;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &L, &R);
        L--;
        R--;
        gcd = query(L, R);
        answer = R - L + 1 - occurrences(gcd, L, R);
        printf("%d\n", answer);
    }
    return 0;
}