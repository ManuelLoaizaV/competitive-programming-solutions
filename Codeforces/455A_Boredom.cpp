//
// Created by ManuelLoaiza on 09/29/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 1e+5;

int a[MAX_N];
ll frequency[MAX_N + 1];
ll dp[MAX_N + 1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        frequency[a[i]]++;
    }
    dp[1] = frequency[1];
    for (int i = 2; i <= MAX_N; i++) {
        if (frequency[i] == 0) dp[i] = dp[i - 1]; 
        else dp[i] = max(dp[i - 2] + i * frequency[i], dp[i - 1]);
    }
    cout << dp[MAX_N] << endl;
    return 0;
}