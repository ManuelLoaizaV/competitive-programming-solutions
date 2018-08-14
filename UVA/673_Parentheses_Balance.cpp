//
// Created by ManuelLoaiza on 02/2818.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    string s;
    getline(cin, s);
    int l;
    char c;
    bool print;
    while (n--) {
        getline(cin, s);
        l = s.size();
        print = true;
        stack<char> balance;
        for (int i = 0; i < l; i++) {
            c = s[i];
            switch (c) {
                case '(' :
                    balance.push(c);
                    break;
                case ')' :
                    if (balance.empty() or balance.top() == '[') print = false;
                    else balance.pop();
                    break;
                case '[' :
                    balance.push(c);
                    break;
                case ']' :
                    if (balance.empty() or balance.top() == '(') print = false;
                    else balance.pop();
                    break;
            }
            if (not print) break;
        }
        if (balance.empty() and print) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
