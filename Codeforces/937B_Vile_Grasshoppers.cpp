//
// Created by ManuelLoaiza on 02/25/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, y;
    scanf("%d %d", &p, &y);
    int current = y;
    if (y % 2 == 0) current--;
    for (current; current > p; current -= 2) {
        bool print = true;
        long long divisor = 3;
        while (divisor * divisor <= current and divisor <= p) {
            if (current % divisor == 0) {
                print = false;
                break;
            } else {
                divisor += 2;
            }
        }
        if (print) {
            printf("%d", current);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}
