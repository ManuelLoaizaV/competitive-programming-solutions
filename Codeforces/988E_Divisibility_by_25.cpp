//
// Created by ManuelLoaiza on 06/01/18
//
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e+18;
int digit[10];

bool enoughDigits() {
	return digit[0] >= 2 or
	digit[5] >= 1 and digit[0] >= 1 or
	digit[2] >= 1 and digit[5] >= 1 or
	digit[7] >= 1 and digit[5] >= 1;
}

long long solve(char d1, char d2, string s) {
	int n = s.size();
	if (s[n - 2] == d1 and s[n - 1] == d2) return 0;
	long long cont = 0;
	
	bool notD2 = true;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == d2) {
			notD2 = false;
			for (int j = i + 1; j < n; j++) {
				swap(s[j], s[j - 1]);
				cont++;
			}
			break;
		}	
	}
	if (notD2) return INF;
	
	bool notD1 = true;
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == d1) {
			notD1 = false;
			for (int j = i + 1; j < n - 1; j++) {
				swap(s[j], s[j - 1]);
				cont++;
			}
			break;
		}	
	}
	if (notD1) return INF;
	
	if (s[0] != '0') return cont;
	
	bool notPossible = true;
	for (int i = 1; i < n - 2; i++) {
		if (s[i] != '0') {
			notPossible = false;
			cont += i;
			break;
		}
	}
	
	if (notPossible) return INF;
	return cont;
}

int main() {
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int l = s.size();
	for (int i = 0; i < l; i++) digit[s[i] - '0']++;
	if (enoughDigits()) {
		long long s1 = solve('0', '0', s);
		long long s2 = solve('2', '5', s);
		long long s3 = solve('5', '0', s);
		long long s4 = solve('7', '5', s);
		long long answer = min(s1, min(s2, min(s3, s4)));
		if (answer == INF) cout << "-1" << endl;
		else cout << answer << endl;
		
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
