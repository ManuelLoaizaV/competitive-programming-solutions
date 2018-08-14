//
//   Created by ManuelLoaiza on 03/14/2018.
//
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_CENTS = 30000;
int coins[5] = {1, 5, 10, 25, 50};
long long dp[MAX_CENTS + 1][5];

long long coinChange(int cents, int index) {
    if (cents == 0) return 1;
    if (cents < 0) return 0;
    if (index < 0) return 0;
    if (dp[cents][index] != -1) return dp[cents][index];
    dp[cents][index] = coinChange(cents, index - 1) + coinChange(cents - coins[index], index);
    return dp[cents][index];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int cents;
    long long ways;
    while (cin >> cents) {
        ways = coinChange(cents, 4);
        if (ways == 1) printf("There is only 1 way to produce %d cents change.\n", cents);
        else printf("There are %lld ways to produce %d cents change.\n", ways, cents);
    }
    return 0;
}
