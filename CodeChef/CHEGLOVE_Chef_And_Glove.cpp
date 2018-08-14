//
// Created by ManuelLoaiza on 03/03/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
int fingerLenght[MAX_N];
int sheathLenght[MAX_N];

void solve() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &fingerLenght[i]);
    for (int i = 0; i < N; i++) scanf("%d", &sheathLenght[i]);

    bool front, back;
    front = back = true;
    for (int i = 0; i < N; i++) {
        if (sheathLenght[i] < fingerLenght[i]) {
            front = false;
            break;
        }
    }
    for (int i = 0; i < N; i++) {
        if (sheathLenght[i] < fingerLenght[N - i - 1]) {
            back = false;
            break;
        }
    }
    if (front and back) {
        printf("both\n");
        return;
    }
    if (front) {
        printf("front\n");
        return;
    }
    if (back) {
        printf("back\n");
        return;
    }
    printf("none\n");
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
