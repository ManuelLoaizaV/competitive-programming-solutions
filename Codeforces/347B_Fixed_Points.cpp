//
// Created by ManuelLoaiza on 03/01/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
struct permutation {
    int number;
    int index;
} numbers[MAX_N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &(numbers[i].number));
        numbers[i].index = i;
    }

    int answer = 0;
    int extra = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i].number == numbers[i].index) answer++;
        else {
            if (numbers[numbers[i].number].index == numbers[i].number) {
                if (numbers[numbers[i].number].number == numbers[i].index) extra = max(extra, 2);
                else extra = max(extra, 1);
            }
        }
    }
    answer += extra;
    cout << answer << endl;
    return 0;
}
