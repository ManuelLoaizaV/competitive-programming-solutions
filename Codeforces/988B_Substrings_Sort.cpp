//
// Created by ManuelLoaiza on 06/01/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
string s[MAX_N];

bool condition(string &a, string &b) {
	return a.size() < b.size(); 
}

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	
	sort(s, s + n, condition);
	bool print = true;
	for (int i = 0; i < n - 1; i++) {
		int l1 = s[i].size();
		int l2 = s[i + 1].size();
		bool appeared = false;
		for (int j = 0; j < l2 - l1 + 1; j++) {
			if (s[i] == s[i + 1].substr(j, l1)) {
				appeared = true;
				break;
			}
		}
		if (not appeared) {
			print = false;
			break;
		}
	}
	
	if (print) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) cout << s[i] << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}

