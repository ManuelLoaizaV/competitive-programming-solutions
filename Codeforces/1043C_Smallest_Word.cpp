//
// Created by ManuelLoaiza on 10/28/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int l = s.size();
	int answer[l], As[l];
	for (int i = 0; i < l; i++) {
		answer[i] = 0;
		if (i == 0) As[i] = 0;
		else As[i] = As[i - 1];
		if (s[i] == 'a') As[i]++;
	}
	for (int i = 0; i < l; i++) {
		if (s[i] == 'a') {
			if (As[l - 1] - As[i] == 0 or i < l - 1 and s[i + 1] == 'b') {
				//reverse(s.begin(), s.begin() + i);
				answer[i]++;
			}
		} else { // s[i] == 'b'
			if (i < l - 1 and s[i + 1] == 'a') {
				//reverse(s.begin(), s.begin() + i);
				answer[i]++;
			}
		}
	}
	for (int i = 0; i < l; i++) cout << answer[i] << " ";
	return 0;
}
