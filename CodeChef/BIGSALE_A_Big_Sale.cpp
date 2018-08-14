//
// Created by ManuelLoaiza 03/03/18.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    scanf("%d", &N);
    double answer = 0;
    double price, quantity, discount;
    for (int i = 0; i < N; i++) {
        scanf("%lf %lf %lf", &price, &quantity, &discount);
        answer += (quantity * (price - (100 + discount) / 100 * (100 - discount) / 100 * price));
    }
    cout << fixed << setprecision(9) << answer << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return  0;
}
