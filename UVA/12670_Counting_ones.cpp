//
// Created by ManuelLoaiza on 03/06/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 55;
long long dp[MAX_SIZE + 1][2][MAX_SIZE + 1];
char digits[2] = {'0', '1'};
string number;

string toBase2(long long n) {
    if (n == 0) return "0";
    string answer = "";
    while (n > 0) {
        answer = digits[n % 2] + answer;
        n /= 2;
    }
    return answer;
}

long long digitDP(int index, int lower, long long sum) {
    if (index == number.size()) return sum;
    if (dp[index][lower][sum] != -1) return dp[index][lower][sum];
    dp[index][lower][sum] = 0;
    int actualDigit = number[index] - '0';
    if (lower) {
        for (int i = 0; i <= 1; i++) {
            if (i == 0) dp[index][lower][sum] += digitDP(index + 1, 1, sum);
            else dp[index][lower][sum] += digitDP(index + 1, 1, sum + 1);
        }
    } else {
        for (int i = 0; i <= actualDigit; i++) {
            if (i < actualDigit) {
                if (i == 0) dp[index][lower][sum] += digitDP(index + 1, 1, sum);
                else dp[index][lower][sum] += digitDP(index + 1, 1, sum + 1);
            } else {
                if (i == 0) dp[index][lower][sum] += digitDP(index + 1, 0, sum);
                else dp[index][lower][sum] += digitDP(index + 1, 0, sum + 1);
            }
        }
    }
    return dp[index][lower][sum];
}

int main() {
    long long A, B, answer;
    while (scanf("%lld %lld", &A, &B) == 2) {
        number = toBase2(B);
        memset(dp, -1, sizeof(dp));
        answer = digitDP(0, 0, 0);
        A--;
        number = toBase2(A);
        memset(dp, -1, sizeof(dp));
        answer -= digitDP(0, 0, 0);
        printf("%lld\n", answer);
    }
    return 0;
}
