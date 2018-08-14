//
// Created by ManuelLoaiza on 03/20/2018.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long l, r, k;
    scanf("%lld %lld %lld", &l, &r, &k);
    long long upperBound = floor(1.0 * r / k);
    bool noAnswer = true;
    long long answer = 1;
    while (true) {
        if (l <= answer and answer <= r) {
            noAnswer = false;
            printf("%lld ", answer);
        }
        if (answer > upperBound) break;
        answer *= k;
    }
    if (noAnswer) printf("-1");
    return 0;
}
