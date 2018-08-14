//
// Created by ManuelLoaiza on 02/28/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    map <string, int> answer;
    map <string, int> :: iterator it;
    string country;

    while (n--) {
        cin >> country;
        it = answer.find(country);
        if (it == answer.end()) answer[country] = 1;
        else (it->second)++;
        getline(cin, country);
    }

    it = answer.begin();
    for (it; it != answer.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
