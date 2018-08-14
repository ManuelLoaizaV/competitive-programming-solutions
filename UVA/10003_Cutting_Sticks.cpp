//
// Created by ManuelLoaiza on 03/14/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50;
const int MAX_L = 1000;
const int MAX_DP = MAX_N * MAX_L;
int sticks[MAX_N + 2];
int dp[MAX_L + 1][MAX_L + 1];

int cost(int left, int right) {
    if (right - left == 1) return 0;
    if (dp[left][right] != -1) return dp[left][right];
    int aux = MAX_DP;
    for (int current = left + 1; current < right; current++) {
        aux = min(aux, cost(left, current) + cost(current, right));
    }
    dp[left][right] = aux + sticks[right] - sticks[left];
    return dp[left][right];
}

int main() {
    int l, n, answer;
    while (true) {
        scanf("%d", &l);
        if (l == 0) break;
        scanf("%d", &n);
        sticks[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &sticks[i]);
        sticks[n + 1] = l;
        memset(dp, -1, sizeof(dp));
        answer = cost(0, n + 1);
        printf("The minimum cutting is %d.\n", answer);
    }
    return 0;
}
