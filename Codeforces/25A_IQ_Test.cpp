//
// Created by ManuelLoaiza on 02/25/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int evenNumbers = 0, oddNumbers = 0;
    int lastEven, lastOdd;
    int n, number;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> number;
        if (number % 2 == 0) {
            evenNumbers++;
            lastEven = i;
        } else {
            oddNumbers++;
            lastOdd = i;
        }
    }
    if (evenNumbers == 1) cout << lastEven << endl;
    else cout << lastOdd << endl;
    return 0;
}
