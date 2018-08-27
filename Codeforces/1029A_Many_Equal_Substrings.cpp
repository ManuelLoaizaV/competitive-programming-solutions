//
// Created by ManuelLoaiza on 08/25/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 1e+5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int length, kTimes;
	cin >> length >> kTimes;
	string text;
	cin >> text;
	string answer = text;
	int count = 0;
	int i = 0;
	while (count < kTimes) {
		if (i + length <= answer.size()) {
			if (answer.substr(i, length) == text) {
				count++;
			}
		} else {
			bool add = true;
			int temp = answer.size() - i;
			for (int j = 0; j < temp; j++) {
				if (answer[i + j] != text[j]) {
					add = false;
					break;
				}
			}
			if (add) {
				for (int j = temp; j < length; j++) answer += text[j];
				count++;
			}	
		}
		i++;
	}
	cout << answer << endl;
	return 0;
}

