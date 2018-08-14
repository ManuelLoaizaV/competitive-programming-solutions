//
// Created by ManuelLoaiza on 03/05/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
int firstTower[MAX_N], secondTower[MAX_N];
int dp[MAX_N][MAX_N];

int LCS(int n, int m) {
    if (n < 0 or m < 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    dp[n][m] = 0;
    if (firstTower[n] == secondTower[m]) dp[n][m] = 1 + LCS(n - 1, m - 1);
    else dp[n][m] = max(LCS(n, m -1), LCS(n - 1, m));
    return dp[n][m];
}

int main() {
    int N1, N2;
    int testCase = 1;
    while (scanf("%d %d", &N1, &N2) == 2) {
        if (N1 == 0 and N2 == 0) break;
        for (int i = 0; i < N1; i++) scanf("%d", &firstTower[i]);
        for (int i = 0; i < N2; i++) scanf("%d", &secondTower[i]);
        memset(dp, -1, sizeof(dp));
        int answer = LCS(N1 - 1, N2 - 1);
        printf("Twin Towers #%d\n", testCase);
        printf("Number of Tiles : %d\n\n", answer);
        testCase++;
    }
    return 0;
}
