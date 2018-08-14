//
// Created by ManuelLoaiza on 03/0118.
//
#include <bits/stdc++.h>

using namespace std;

string sum(string a, string b) {
    string answer = "";
    int szA = a.size();
    int szB = b.size();
    int L = max(szA, szB);
    int dA, dB, carry = 0;
    for(int i=0; i < L; i++){
        if(szA > 0) dA = a[szA - 1] - '0';
        else dA = 0;
        if(szB > 0) dB = b[szB - 1] -'0';
        else dB = 0;
        int dig = (dA + dB + carry) % 10;
        carry = (dA + dB + carry) / 10;
        answer = char( dig + '0') + answer;
        szA = szA - 1;
        szB = szB - 1;
    }
    if(carry > 0) answer = '1' + answer;
    return answer;
}

int main() {
    string number;
    string answer = "";
    while (cin >> number) {
        if (number[0] == '0') break;
        answer = sum(answer, number);
    }
    cout << answer << endl;
}
