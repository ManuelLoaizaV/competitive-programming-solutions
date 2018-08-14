//
// Created by ManuelLoaiza on 07/03/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_DIGITS = 10;
const int MAX_SUM = 90;
int dp[MAX_DIGITS][2][MAX_SUM][MAX_SUM];
int A, B, K, answer;
string number;

int digitDP(int index, int lower, int digitSum, int actualNumber) {
    if (index == number.size()) {
        if (digitSum == 0 and actualNumber == 0) return 1;
        else return 0;
    }
    if (dp[index][lower][digitSum][actualNumber] != -1) return dp[index][lower][digitSum][actualNumber];
    dp[index][lower][digitSum][actualNumber] = 0;
    if (lower) {
        for (int i = 0; i <= 9; i++) {
            dp[index][lower][digitSum][actualNumber] += digitDP(index + 1, 1, (digitSum + i) % K, int (actualNumber + i * pow(10, number.size() - 1 - index)) % K);
        }
    } else {
        int actualDigit = number[index] - '0';
        for (int i = 0; i <= actualDigit; i++) {
            if (i < actualDigit) dp[index][lower][digitSum][actualNumber] += digitDP(index + 1, 1, (digitSum + i) % K, int (actualNumber + i * pow(10, number.size() - 1 - index)) % K);
            else dp[index][lower][digitSum][actualNumber] += digitDP(index + 1, 0, (digitSum + i) % K, int (actualNumber + i * pow(10, number.size() - 1 - index)) % K);
        }
    }
    return dp[index][lower][digitSum][actualNumber];
}

void solve() {
    scanf("%d %d %d", &A, &B, &K);
    if (K > 90) answer = 0;
    else {
        memset(dp, -1, sizeof(dp));
        number = to_string(B);
        answer = digitDP(0, 0, 0, 0);
        memset(dp, -1, sizeof(dp));
        number = to_string(A - 1);
        answer -= digitDP(0, 0, 0, 0);
    }
    printf("%d\n", answer);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
