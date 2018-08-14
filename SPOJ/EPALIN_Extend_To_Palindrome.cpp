//
// Created by ManuelLoaiza on 05/29/18
//
#include <bits/stdc++.h>

using namespace std;

void KMP(string &p, string &t) {
	int n = p.size();
	int m = t.size();
	vector <int> border(n + m + 1);
	string s = p + '#' + t;
	for (int i = 1; i < n + m + 1; i++) {
		int j = border[i - 1];
		while (j > 0 and s[i] != s[j]) j = border[j - 1];
		if (s[i] == s[j]) j++;
		border[i] = j;
	}
	
	int similarity = border[n + m];
	cout << t;
	for (int i = m - similarity - 1; i >= 0; i--) cout << t[i];
	cout << endl;
}

int main() {
	string s;
	while (cin >> s) {
		string r = s;
		reverse(r.begin(), r.end());
		KMP(r, s);
	}
	return 0;
}
