//
// Created by ManuelLoaiza on 02/26/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1024;

struct FenwickTree {
    long long tree[MAX + 1][MAX + 1];
    long long numbers[MAX + 1][MAX + 1];

    FenwickTree(int n) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                tree[i][j] = 0;
                numbers[i][j] = 0;
            }
        }
    }

    long long query(int i, int j) {
        long long sum = 0;
        while (i > 0) {
            int k = j;
            while (k > 0) {
                sum += tree[i][k];
                k -= (k & -k);
            }
            i -= (i & -i);
        }
        return sum;
    }

    void update(int i, int j, long long number) {
        long long delta = number - numbers[i][j];
        numbers[i][j] = number;
        while (i <= MAX) {
            int k = j;
            while (k <= MAX) {
                tree[i][k] += delta;
                k += (k & -k);
            }
            i += (i & -i);
        }
    }
};

void solve() {
    int n;
    scanf("%d", &n);
    FenwickTree ft(n);
    char s[4];
    while (scanf("%s", s)) {
        if (s[0] == 'E') break;
        if (s[1] == 'E') {
            int x, y;
            long long number;
            scanf("%d %d %lld", &x, &y, &number);
            x++;
            y++;
            ft.update(x, y, number);
        } else {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x1++;
            y1++;
            x2++;
            y2++;
            long long result = ft.query(x2, y2) - ft.query(x1 - 1, y2) - ft.query(x2, y1 - 1) + ft.query(x1 - 1, y1 - 1);
            printf("%lld\n", result);
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
