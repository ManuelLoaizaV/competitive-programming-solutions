//
// Created by ManuelLoaiza on 02/07/18.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e+5;
const int MAX_A = 1e+6;
const int MAX_Q = 2e+5;
int tree[MAX_N + 1];
int A[MAX_N + 1];
int lastIndex[MAX_A + 1];
int answer[MAX_Q];

struct FenwickTree {
    void update(int i, int delta) {
        while (i <= MAX_N) {
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

struct Query {
    int index;
    int left;
    int right;
    bool operator < (Query b) const {
        if (right == b.right) return left < b.left;
        return right < b.right;
    }
} queries[MAX_Q];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    int Q;
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &queries[i].left, &queries[i].right);
        queries[i].index = i;
    }
    sort(queries, queries + Q);
    memset(lastIndex, -1, sizeof(lastIndex));

    int index = 0;
    for (int i = 1; i <= N; i++) {
        if (lastIndex[A[i]] != -1) ft.update(lastIndex[A[i]], -1);
        lastIndex[A[i]] = i;
        ft.update(i, 1);
        while (index < Q and queries[index].right == i) {
            answer[queries[index].index] = ft.query(queries[index].right) - ft.query(queries[index].left - 1);
            index++;
        }
    }

    for (int i = 0; i < Q; i++) {
        printf("%d\n", answer[i]);
    }

    return 0;
}
