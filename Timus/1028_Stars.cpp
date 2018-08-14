//
// Created by ManuelLoaiza on 02/27/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 15000;
const int MAX_COORDINATE = 32000;
int tree[MAX_COORDINATE + 2];
int answer[MAX_N];

struct FenwickTree {
    void update(int i, int delta) {
        while (i <= MAX_COORDINATE + 1) {
            tree[i] += delta;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }
} ft;

int main() {
    int n;
    scanf("%d", &n);

    int x, y;
    int level;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        x++;
        level = ft.query(x);
        ft.update(x, 1);
        answer[level]++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", answer[i]);
    }
    return 0;
}
