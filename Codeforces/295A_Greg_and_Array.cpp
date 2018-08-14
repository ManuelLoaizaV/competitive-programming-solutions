//
// Created by ManuelLoaiza on 02/26/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e+5;

long long numbers[MAX + 2];
long long queries[MAX + 2];
long long delta[MAX + 2];

struct Operation {
    int l;
    int r;
    long long d;
} operations[MAX + 2];

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &numbers[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %lld", &operations[i].l, &operations[i].r, &operations[i].d);
    }
    int x, y;
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &x, &y);
        queries[x]++;
        queries[y + 1]--;
    }
    long long accumulated = 0;
    for (int i = 1; i <= m; i++) {
        accumulated += queries[i];
        operations[i].d *= accumulated;
        delta[operations[i].l] += operations[i].d;
        delta[operations[i].r + 1] -= operations[i].d;
    }

    long long newDelta = 0;
    long long result;
    for (int i = 1; i <= n; i++) {
        newDelta += delta[i];
        result = numbers[i] + newDelta;
        printf("%lld ", result);
    }

    return 0;
}
