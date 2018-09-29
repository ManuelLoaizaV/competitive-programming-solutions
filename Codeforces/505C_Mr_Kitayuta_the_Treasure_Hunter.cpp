//
// Created by ManuelLoaiza on 09/29/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e+4;

int limit;
int dp[MAX_N + 1][600];
int frequency[MAX_N + 1];

void findLimit(int d) {
    int temp = 0;
    for (int i = d; i > 0; i--) {
        temp += i;
        if (temp <= MAX_N) limit = i;
        else break;
    }
}

int f(int u, int d) {
    if (u > MAX_N) return 0;
    if (d <= 0) return 0;
    int l = d - limit;
    if (dp[u][l] != -1) return dp[u][l];
    int f1 = f(u + d - 1, d - 1);
    int f2 = f(u + d, d);
    int f3 = f(u + d + 1, d + 1);
    dp[u][l] = frequency[u] + max(f1, max(f2, f3));
    return dp[u][l];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int n, d, x;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> x;
        frequency[x]++;
    }
    findLimit(d);
    int answer = f(d, d);
    cout << answer << endl;
    return 0;
}