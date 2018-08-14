//
// Created by ManuelLoaiza on 03/03/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
int A[MAX_N];

void solve() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    int answer = 0;
    sort(A, A + N);
    for (int i = N - 1; i > 0; i--) {
        if (A[i] == A[i - 1]) answer++;
    }
    printf("%d\n", answer);    
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
