//
// Created by ManuelLoaiza on 02/07/18.
// Last update on 16/02/18
//

#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+4;
const int MAX_INT = 1e+5;
const int MOD = 5e+6;
const int MAX_K = 50;
long long tree[MAX_K + 1][MAX_INT + 1];

struct FenwickTree {
    void update(int k, int index, int delta) {
        while (index <= MAX_INT) {
            tree[k][index] += delta;
            index += (index & - index);
        }
    }

    int query (int k, int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[k][index];
            index -= (index & - index);
            if (sum >= MOD) sum %= MOD;
        }
        return sum;
    }
} ft;

int main() {

    int N, K, number;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> number;
        for (int k = K; k > 1; kTuple--) {
            ft.update(k, number + 1, ft.query(k - 1, number));
        }
        ft.update(1, number + 1, 1);
    }

    cout << ft.query(K, MAX_INT) << endl;

    return 0;
}
