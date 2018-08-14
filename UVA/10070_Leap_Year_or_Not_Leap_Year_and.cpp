//
// Created by ManuelLoaiza on 01/30/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long year;
    bool primeraVez = 1;

    while (cin >> year) {
        bool leapYear = 0, huluculu = 0, bulukulu = 0;
        if (primeraVez) {
            primeraVez = 0;
        } else {
            cout << endl;
        }
        if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0) {
            leapYear = 1;
        }
        if (year % 15 == 0) {
            huluculu = 1;
        }
        if (leapYear and year % 55 == 0) {
            bulukulu = 1;
        }
        if (not leapYear and not huluculu and not bulukulu) {
            cout << "This is an ordinary year." << endl;
        } else {
            if (leapYear) {
                cout << "This is leap year." << endl;
            }
            if (huluculu) {
                cout << "This is huluculu festival year." << endl;
            }
            if (bulukulu) {
                cout << "This is bulukulu festival year." << endl;
            }
        }
    }
    return 0;
}

/*
# mi solucion en Python

primeraVez = True

try:
    while True:
        year = int(input())
        leap = False
        huluculu = False
        bulukulu = False
        if primeraVez :
            primeraVez = False
        else :
            print()
        if ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0) :
            leap = True
        if (year % 15 == 0) :
            huluculu = True
        if (leap and year % 55 == 0) :
            bulukulu = True
        if (not leap and not huluculu and not bulukulu) :
            print ('This is an ordinary year.')
        else :
            if leap :
                print ('This is leap year.')
            if huluculu :
                print ('This is huluculu festival year.')
            if bulukulu :
                print ('This is bulukulu festival year.')
except EOFError:
    pass

 */
