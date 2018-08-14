//
// Created by ManuelLoaiza on 02/25/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int answer = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            current++;
        } else {
            if (a[i] >= a[i - 1]) current++;
            else current = 1;
        }
        answer = max(answer, current);
    }
    cout << answer << endl;
    return 0;
}
