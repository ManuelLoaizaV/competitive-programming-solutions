//
// Created by ManuelLoaiza on 03/01/18.
//
#include <bits/stdc++.h>

using namespace std;

string type[5] = {"byte", "short", "int", "long", "BigInteger"};
string negativeLimit[4] = {"128", "32768", "2147483648", "9223372036854775808"};
string positiveLimit[4] = {"127", "32767", "2147483647", "9223372036854775807"};

int main() {
    string number;
    cin >> number;
    int l = number.size();
    short answer = -1;
    if (number[0] == '-') {
        l--;
        number.erase(number.begin());
        if (l <= 3) {
            if (l <= 2) {
                answer = 0;
            } else {
                for (int i = 0; i < l; i++) {
                    if (number[i] != negativeLimit[0][i]) {
                        if (number[i] < negativeLimit[0][i]) answer = 0;
                        if (number[i] > negativeLimit[0][i]) answer = 1;
                        break;
                    }
                }
                if (answer == -1) answer = 0;
            }
        } else {
            if (l <= 5) {
                if (l <= 4) {
                    answer = 1;
                } else {
                    for (int i = 0; i < l; i++) {
                        if (number[i] != negativeLimit[1][i]) {
                            if (number[i] < negativeLimit[1][i]) answer = 1;
                            if (number[i] > negativeLimit[1][i]) answer = 2;
                            break;
                        }
                    }
                    if (answer == -1) answer = 1;
                }
            } else {
                if (l <= 10) {
                    if (l <= 9) {
                        answer = 2;
                    } else {
                        for (int i = 0; i < l; i++) {
                            if (number[i] != negativeLimit[2][i]) {
                                if (number[i] < negativeLimit[2][i]) answer = 2;
                                if (number[i] > negativeLimit[2][i]) answer = 3;
                                break;
                            }
                        }
                        if (answer == -1) answer = 2;
                    }
                } else {
                    if (l <= 19) {
                        if (l <= 18) {
                            answer = 3;
                        } else {
                            for (int i = 0; i < l; i++) {
                                if (number[i] != negativeLimit[3][i]) {
                                    if (number[i] < negativeLimit[3][i]) answer = 3;
                                    if (number[i] > negativeLimit[3][i]) answer = 4;
                                    break;
                                }
                            }
                            if (answer == -1) answer = 3;
                        }
                    } else {
                        answer = 4;
                    }
                }
            }
        }
    } else {
        if (l <= 3) {
            if (l <= 2) {
                answer = 0;
            } else {
                for (int i = 0; i < l; i++) {
                    if (number[i] != positiveLimit[0][i]) {
                        if (number[i] < positiveLimit[0][i]) answer = 0;
                        if (number[i] > positiveLimit[0][i]) answer = 1;
                        break;
                    }
                }
                if (answer == -1) answer = 0;
            }
        } else {
            if (l <= 5) {
                if (l <= 4) {
                    answer = 1;
                } else {
                    for (int i = 0; i < l; i++) {
                        if (number[i] != positiveLimit[1][i]) {
                            if (number[i] < positiveLimit[1][i]) answer = 1;
                            if (number[i] > positiveLimit[1][i]) answer = 2;
                            break;
                        }
                    }
                    if (answer == -1) answer = 1;
                }
            } else {
                if (l <= 10) {
                    if (l <= 9) {
                        answer = 2;
                    } else {
                        for (int i = 0; i < l; i++) {
                            if (number[i] != positiveLimit[2][i]) {
                                if (number[i] < positiveLimit[2][i]) answer = 2;
                                if (number[i] > positiveLimit[2][i]) answer = 3;
                                break;
                            }
                        }
                        if (answer == -1) answer = 2;
                    }
                } else {
                    if (l <= 19) {
                        if (l <= 18) {
                            answer = 3;
                        } else {
                            for (int i = 0; i < l; i++) {
                                if (number[i] != positiveLimit[3][i]) {
                                    if (number[i] < positiveLimit[3][i]) answer = 3;
                                    if (number[i] > positiveLimit[3][i]) answer = 4;
                                    break;
                                }
                            }
                            if (answer == -1) answer = 3;
                        }
                    } else {
                        answer = 4;
                    }
                }
            }
        }
    }
    cout << type[answer] << endl;
    return 0;
}
