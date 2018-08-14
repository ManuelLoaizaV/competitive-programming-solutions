//
// Created by ManuelLoaiza on 05/29/18
//
#include <bits/stdc++.h>

using namespace std;

void KMP() {
	int n;
	string s;
	cin >> n >> s;
	vector <int> border(n);
	for (int i = 1; i < n; i++) {
		int j = border[i - 1];
		while (j > 0 and s[i] != s[j]) j = border[j - 1];
		if (s[i] == s[j]) j++;
		border[i] = j;
		
		if (border[i] > 0) {
			int l = i + 1;
			int a = l - border[i];
			if (l % a == 0) {
				cout << l << " " << l / a << endl;
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Test case #" << i << endl;
		KMP();
		cout << endl;
	}
	return 0;
}

