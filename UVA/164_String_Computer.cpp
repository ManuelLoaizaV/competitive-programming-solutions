//
// Created by ManuelLoaiza on 03/13/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 20;
string origin, target;
int dp[MAX_N][MAX_N];
int aux;

int LCS(int n, int m) {
    if (n < 0 or m < 0) return max(n + 1, m + 1);
    if (dp[n][m] != -1) return dp[n][m];
    dp[n][m] = 0;
    if (origin[n] == target[m]) dp[n][m] = LCS(n - 1, m - 1);
    else dp[n][m] = 1 + min(LCS(n - 1, m - 1), min(LCS(n, m - 1), LCS(n - 1, m)));
    return dp[n][m];
}

void reconstruct(int n, int m) {
    if (n < 0 or m < 0) {
        if (n < 0) {
            for (int i = 0; i < m + 1; i++) {
                printf("I%c", target[i]);
                if (i < 9) printf("0%d", i + 1);
                else printf("%d", i + 1);
                aux++;
            }
        } else {
            for (int i = 0; i < n + 1; i++) {
                printf("D%c01", origin[i]);
                aux--;
            }
        }
        return;
    }
    if (origin[n] == target[m]) reconstruct(n - 1, m - 1);
    else {
        if (LCS(n, m) == 1 + LCS(n - 1, m - 1)){
            reconstruct(n - 1, m - 1);
            printf("C%c", target[m]);
            if (n + aux < 9) printf("0%d", n + aux + 1);
            else printf("%d", n + aux + 1);
        } else {
            if (LCS(n, m) == 1 + LCS(n, m - 1)){
                reconstruct(n, m - 1);
                printf("I%c", target[m]);
                if (n + 1 + aux < 9) printf("0%d", n + aux + 2);

                else printf("%d", n + aux + 2);
                aux++;
            } else {
                reconstruct(n - 1, m);
                printf("D%c", origin[n]);
                if (n + aux< 9) printf("0%d", n + aux + 1);
                else printf("%d", n + aux + 1);
                aux--;
            }
        }
    }
}

int main(){
    while (true) {
        cin >> origin;
        if (origin[0] == '#') break;
        cin >> target;
        memset(dp, -1, sizeof(dp));
        aux = 0;
        LCS(origin.size() - 1, target.size() - 1);
        reconstruct(origin.size() - 1, target.size() - 1);
        printf("E\n");
    }
    return 0;
}