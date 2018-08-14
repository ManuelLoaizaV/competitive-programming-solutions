//
// Created by ManuelLoaiza on 03/03/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+6;
int firstPrimeDivisor[MAX_N + 1];
int N[MAX_N];

void extendedSieve() {
    firstPrimeDivisor[0] = firstPrimeDivisor[1] = 1;
    for (int i = 2; i * i <= MAX_N; i++) {
        if (firstPrimeDivisor[i] == 0) {
            firstPrimeDivisor[i] = i;
            for (int j = i * i; j <= MAX_N; j += i) {
                firstPrimeDivisor[j] = i;
            }
        }
    }
    for (int i = sqrt(MAX_N); i <= MAX_N; i++) {
        if (firstPrimeDivisor[i] == 0) firstPrimeDivisor[i] = i;
    }
}

int numberOfDivisors(int number) {
    int result = 1;
    int exponent, divisor;
    while (number > 1) {
        divisor = firstDivisor[number];
        exponent = 0;
        while (number % divisor == 0) {
            number /= divisor;
            exponent++;
        }
        result *= (exponent + 1);
    }
    return result;
}

void precompute() {
    N[0] = 1;
    int index = 1;
    while (N[index - 1] <= MAX_N) {
        N[index] = N[index - 1] + numberOfDivisors(N[index - 1]);
        index++;
    }
    sort(N, N + MAX_N);
}

int main() {
    extendedSieve();
    precompute();
    int T, A, B, answer;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d %d", &A, &B);
        answer = upper_bound(N, N + MAX_N, B) - lower_bound(N, N + MAX_N, A);
        printf("Case %d: %d\n", i, answer);
    }
    return 0;
}
