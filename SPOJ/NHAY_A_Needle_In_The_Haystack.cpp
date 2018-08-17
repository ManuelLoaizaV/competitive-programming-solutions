//
// Created by ManuelLoaiza on 05/27/18
//
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
	int x;
	string p, t;
	while (cin >> x) {
		cin >> p >> t;
		int n = p.size();
		int m = t.size();
		vector <int> b(n + m + 1), answer;
		string s = p + '#' + t;
		for (int i = 1; i < n + m + 1; i++) {
			int j = b[i - 1];
			while (j > 0 and s[i] != s[j]) j = b[j - 1];
			if (s[i] == s[j]) j++;
			b[i] = j;
			if (b[i] == n) answer.push_back(i - (n + 1) - n + 1);
		}
		int l = answer.size();
		for (int i = 0; i < l; i++) cout << answer[i] << endl;
		cout << endl;
	}
} 
