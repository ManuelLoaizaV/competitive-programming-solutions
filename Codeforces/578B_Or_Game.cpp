//
// Created by ManuelLoaiza on 03/19/2018.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e+5;
long long a[MAX_N], acLeft[MAX_N], acRight[MAX_N];

int main() {
    long long n, k, x;
    scanf("%lld %lld %lld", &n, &k, &x);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < n; i++) {
        if (i == 0) acLeft[i] = a[i];
        else acLeft[i] = a[i] | acLeft[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) acRight[i] = a[i];
        else acRight[i] = a[i] | acRight[i + 1];
    }
    long long answer = 0;
    long long operation = pow(x, k);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            answer = max(answer, (a[i] * operation) | acRight[i + 1]);
        } else {
            if (i == n - 1) {
                answer = max(answer, acLeft[i - 1] | (a[i] * operation));
            } else {
                answer = max(answer, acLeft[i - 1] | (a[i] * operation) | acRight[i + 1]);
            }
        }
    }
    printf("%lld", answer);
    return 0;
}
