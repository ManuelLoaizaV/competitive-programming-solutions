//
// Created by ManuelLoaiza on 03/03/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
int bananas[MAX_N];

int binarySearch(int left, int right, int answer, int n, int h) {
    if (right >= left) {
        int middle = (left + right) / 2;
        long long numberOfHours = 0;
        for (int i = 0; i < n; i++) numberOfHours += ceil(1.0 * bananas[i] / middle);
        if (left == right) {
            if (numberOfHours <= h) return middle;
            else return answer;
        } else {
            if (numberOfHours <= h) return binarySearch(left, middle - 1, middle, n, h);
            else return binarySearch(middle + 1, right, answer, n, h);
        }
    } else {
        return answer;
    }
}

void solve() {
    int N, H;
    int maxAnswer = 0;
    scanf("%d %d", &N, &H);
    for (int i = 0; i < N; i++) {
        scanf("%d", &bananas[i]);
        maxAnswer = max(maxAnswer, bananas[i]);
    }
    int answer = binarySearch(1, maxAnswer, maxAnswer, N, H);
    printf("%d\n", answer);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
