//
// Created by ManuelLoaiza on 03/16/18
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1 << 15;
int ways[MAX_N];

void precalculate() {
    int i2, j2, k2, l2;
    for (int i = 0; i * i < MAX_N; i++) {
        i2 = i * i;
        for (int j = i; j * j + i2 < MAX_N; j++) {
            j2 = j * j;
            for (int k = j; k * k + i2 + j2 < MAX_N; k++) {
                k2 = k * k;
                for (int l = k; l * l + k2 + j2 + i2 < MAX_N; l++) {
                    l2 = l * l;
                    ways[i2 + j2 + k2 + l2]++;
                }
            }
        }
    }
}

int main() {
    precalculate();
    int n;
    while (scanf("%d", &n)) {
        if (n == 0) break;
        printf("%d\n", ways[n]);
    }
    return 0;
}