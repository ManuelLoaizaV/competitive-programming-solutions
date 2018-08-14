//
// Created by ManuelLoaiza on 05/31/18
//
#include <bits/stdc++.h>

using namespace std;

int KMP(string &p, string &t) {
	int n = p.size();
	int m = t.size();
	string s = p + '#' + t;
	vector <int> border(n + m + 1);
	for (int i = 1; i < n + m + 1; i++) {
		int j = border[i - 1];
		while (j > 0 and s[i] != s[j]) j = border[j - 1];
		if (s[i] == s[j]) j++;
		border[i] = j;
		if (border[i] == n) return n;
	}
	return border[n + m];
}

int solve(string &a, string &b, string &c) {
	string ab = a;
	int similarity_a_b = KMP(b, a);
	int bSize = b.size(); 
	for (int i = similarity_a_b; i < bSize; i++) ab += b[i];
	string abc = ab;
	int similarity_ab_c = KMP(c, ab);
	int cSize = c.size();
	for (int i = similarity_ab_c; i < cSize; i++) abc += c[i];
	return abc.size();	
}

int main() {
	std::ios::sync_with_stdio(false);
	string s1, s2, s3;
	while (cin >> s1 >> s2 >> s3) {
		int answer = s1.size() + s2.size() + s3.size();
		answer = min(answer, solve(s1, s2, s3));
		answer = min(answer, solve(s1, s3, s2));
		answer = min(answer, solve(s2, s1, s3));
		answer = min(answer, solve(s2, s3, s1));
		answer = min(answer, solve(s3, s1, s2));
		answer = min(answer, solve(s3, s2, s1));
		cout << answer << endl;
	}
	return 0;
}

