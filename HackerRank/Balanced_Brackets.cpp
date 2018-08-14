//
// Created by ManuelLoaiza on 03/29/18
//
#include <bits/stdc++.h>

using namespace std;

bool isOpeningBracket(char &c) {
	return c == '{' or c == '[' or c == '(';
}

bool match(char &a, char &b) {
	if (a == '{' and b == '}' or
		a == '[' and b == ']' or
		a == '(' and b == ')')
	return true;
	return false;
}

void solve() {
	string line;
	cin >> line;
	stack<char> balance;
	
	for (int i = 0; i < line.size(); i++) {
		if (isOpeningBracket(line[i])) {
			balance.push(line[i]);
		} else { // is a closing bracket
			if (balance.empty() or not match(balance.top(), line[i])) {
				cout << "NO" << endl;
				return;
			} else {
				balance.pop();
			}
		}
	}
	
	if (balance.empty()) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	int testCases;
	cin >> testCases;
	while (testCases--) solve(); 
	return 0;
}

