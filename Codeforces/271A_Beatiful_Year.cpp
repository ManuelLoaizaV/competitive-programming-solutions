//
// Created by ManuelLoaiza on 02/09/18.
//

#include <iostream>

using namespace std;

bool distinctDigits(int year) {
    bool digits[10];

    for (int i = 0; i < 10; i++) {
        digits[i] = false;
    }

    while (year > 0) {
        int lastDigit = year % 10;
        if (digits[lastDigit]) return false;
        digits[lastDigit] = true;
        year /= 10;
    }

    return true;
}

int beatifulYear(int year) {
    while (true) {
        if (distinctDigits(year)) return year;
        year++;
    }
}

int main() {
    int year;
    cin >> year;
    cout << beatifulYear(year + 1) << endl;
    return 0;
}
