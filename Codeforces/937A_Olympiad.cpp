//
// Created by ManuelLoaiza on 02/25/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_A = 600;
bool appear[MAX_A + 1];

int main() {
    int n;
    cin >> n;
    int score;
    for (int i = 0; i < n; i++) {
        cin >> score;
        appear[score] = 1;
    }
    int result = 0;
    for (int i = 1; i <= MAX_A; i++) {
        if (appear[i]) result++;
    }
    cout << result << endl;
    return 0;
}
