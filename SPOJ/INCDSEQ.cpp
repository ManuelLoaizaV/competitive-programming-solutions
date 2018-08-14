//
// Created by manuelloaiza on 27/02/18.
// Last update on 01/03/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+4;
const int MAX_K = 50;
const int MOD = 5e+6;
bool used[MAX_N + 1];
long long numbers[MAX_N], aux[MAX_N];
map <long long, int> transformation;

struct FenwickTree {
    int tree[MAX_K + 1][MAX_N + 1];

    void update(int k, int i, int delta) {
        if (delta < 0) delta += MOD;
        while (i <= MAX_N) {
            tree[k][i] += delta;
            if (tree[k][i] >= MOD) tree[k][i] -= MOD;
            i += (i & -i);
        }
    }

    int query(int k, int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[k][i];
            if (sum >= MOD) sum -= MOD;
            i -= (i & -i);
        }
        return sum;
    }
} ft;

int main() {
    int n, K;
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &numbers[i]);
        aux[i] = numbers[i];
    }

    sort(aux, aux + n);
    int newNumber = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0 or aux[i] > aux[i - 1]) {
            transformation[aux[i]] = newNumber;
            newNumber++;
        }
    }

    int delta;
    for (int i = 0; i < n; i++) {
        newNumber = transformation.find(aux[i])->second;
        for (int k = K; k > 1; k--) {
            delta = ft.query(k - 1, newNumber - 1) - ft.query(k, newNumber) + ft.query(k, newNumber - 1);
            ft.update(k, newNumber, delta);
        }
        if (not used[newNumber]) {
            ft.update(1, newNumber, 1);
            used[newNumber] = true;
        }
    }

    cout << ft.query(K, MAX_N) << endl;
    return 0;
}