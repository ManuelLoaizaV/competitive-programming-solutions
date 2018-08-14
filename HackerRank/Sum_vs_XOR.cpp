//
// Created by ManuelLoaiza on 05/20/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	long long answer = 1;
	if (n > 0) {
		while (n > 1) {
			if (n % 2 == 0) answer *= 2;
			n /= 2;
		}
	}
	cout << answer << endl;
	return 0;
}

