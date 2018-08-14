//
// Created by ManuelLoaiza on 03/11/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
const long long MAX_MASK = 1 << MAX_N;

bool preferences[MAX_N][MAX_N];
long long dp[MAX_N][MAX_MASK];
int n;

long long bitmaskDP(int position, long long mask) {
    if (position == n) {
        if (mask == (1 << n) - 1) return 1;
        else return 0;
    }
    if (dp[position][mask] != -1) return dp[position][mask];
    dp[position][mask] = 0;
    for (int i = 0; i < n; i++) {
        if (not ((mask >> i) & 1) and preferences[position][i])
            dp[position][mask] += bitmaskDP(position + 1, mask | (1 << i));
    }
    return dp[position][mask];
}

void solve() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &(preferences[i][j]));
        }
    }
    long long answer = bitmaskDP(0, 0);
    printf("%lld\n", answer);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
