//
// Created by ManuelLoaiza on 3/20/2018.
//
#include <bits/stdc++.h>

using namespace std;

bool condition(const char &a, const char &b) {
    if (isupper(a) and isupper(b)) return a < b;
    if (not isupper(a) and not isupper(b)) return a < b;
    if (tolower(a) == tolower(b)) return isupper(a);
    return tolower(a) < tolower(b);
}

void solve() {
    string word;
    cin >> word;
    sort(word.begin(), word.end(), condition);
    cout << word << endl;
    while (next_permutation(word.begin(), word.end(), condition)) cout << word << endl;
}

int main() {
    int n;
    scanf("%d", &n);
    while(n --) solve();
}