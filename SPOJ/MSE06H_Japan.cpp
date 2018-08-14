//
// Created by ManuelLoaiza on 02/06/18.
//

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e+3;
long long tree[MAX + 1];

struct Highway {

    long long eastCoastCity;
    long long westCoastCity;

    bool operator < (Highway auxiliary) const {
        if (eastCoastCity == auxiliary.eastCoastCity) {
            return westCoastCity < auxiliary.westCoastCity;
        } else {
            return eastCoastCity < auxiliary.eastCoastCity;
        }
    }
} highways[MAX * MAX];

struct FeinwickTree {

    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

    void update(int i, long long delta) {
        while (i <= MAX) {
            tree[i] += delta;
            i += (i & -i);
        }
    }
} ft;

long long answer() {

    memset(tree, 0, sizeof(tree));

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        cin >> highways[i].eastCoastCity >> highways[i].westCoastCity;
    }

    sort(highways, highways + K);

    long long numberOfCrossings = 0;

    for (int i = 0; i < K; i++) {
        ft.update(highways[i].westCoastCity, 1);
        numberOfCrossings += (ft.query(M) - ft.query(highways[i].westCoastCity));
    }

    return numberOfCrossings;
};

int main() {

    int testCases;
    cin >> testCases;

    for (int i = 1; i <= testCases; i++) {
        printf("Test case %d: %lld\n", i, answer());
    }

    return 0;
}
