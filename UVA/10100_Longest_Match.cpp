//
// Created by ManuelLoaiza on 03/05/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 500;
int dp[MAX_SIZE][MAX_SIZE], answer;
string firstMessage, secondMessage, aux;
vector<string> firstTokens, secondTokens;

void punctuationToWhiteSpaces(string &s) {
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] < 'a' or s[i] > 'z') and (s[i] < 'A' or s[i] > 'Z')
            and (s[i] < '0' or s[i] > '9')) s[i] = ' ';
    }
}

int LCS(int n, int m) {
    if (n < 0 or m < 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    dp[n][m] = 0;
    if (firstTokens[n] == secondTokens[m]) dp[n][m] = 1 + LCS(n - 1, m - 1);
    else dp[n][m] = max(LCS(n, m - 1), LCS(n - 1, m));
    return dp[n][m];
}

int main() {
    int testCase = 1;
    while (getline(cin, firstMessage)) {
        getline(cin, secondMessage);
        punctuationToWhiteSpaces(firstMessage);
        punctuationToWhiteSpaces(secondMessage);
        stringstream ss1(firstMessage);
        stringstream ss2(secondMessage);
        firstTokens.clear();
        secondTokens.clear();
        while (ss1 >> aux) firstTokens.push_back(aux);
        while (ss2 >> aux) secondTokens.push_back(aux);
        int n = firstTokens.size();
        int m = secondTokens.size();
        cout << setw(2) << testCase;
        if (n == 0 or m == 0) printf(". Blank!\n");
        else {
            memset(dp, -1, sizeof(dp));
            answer = LCS(n - 1, m - 1);
            printf(". Length of longest match: %d\n", answer);
        }
        testCase++;
    }
    return 0;
}
