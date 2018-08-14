//
// Created by ManuelLoaiza on 02/28/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (answer.empty() or answer[answer.size() - 1] != s[i]) {
            answer += s[i];
        } else {
            answer.erase(answer.size() - 1);
        }
    }
    cout << answer << endl;
    return 0;
}
