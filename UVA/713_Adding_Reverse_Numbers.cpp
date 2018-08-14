//
// Created by ManuelLoaiza on 05/18/18
//
#include <bits/stdc++.h>

using namespace std;

void clearReverse(string &s) {
	while (s.size() > 1 and s[0] == '0') {
		s.erase(0, 1);
	}
}

void reverse(string &s) {
	int n = s.size();
	for (int i = 0; i < n / 2; i++) swap(s[i], s[n - i - 1]);
}

string sum(string a, string b ){
	string ans = "";
	int szA = a.size();
	int szB = b.size();
	int L = max(szA, szB);
	int dA, dB, carry = 0;
	for (int i = 0; i < L; i++){
		if(szA > 0) dA = a[szA - 1] - '0';
		else dA = 0;
		if(szB > 0) dB = b[szB - 1] -'0';
		else dB = 0;
		int dig = (dA + dB + carry) % 10;
		carry = (dA + dB + carry) / 10;
		ans = char(dig + '0') + ans ;
		szA = szA - 1;
		szB = szB - 1;
	}
	if(carry > 0) ans = '1' + ans;
	return ans;
}

void solve() {
	string a, b, answer;
	cin >> a >> b;
	reverse(a);
	reverse(b);
	answer = sum(a, b);
	reverse(answer);
	clearReverse(answer);
	cout << answer << endl;
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) solve();
	return 0;
}
