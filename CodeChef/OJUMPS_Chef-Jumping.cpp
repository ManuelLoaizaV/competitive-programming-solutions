//
// Created by ManuelLoaiza on 05/21/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a;
	cin >> a;
	
	if (a % 6 == 0 or (a - 3) % 6 == 0 or (a - 1) % 6 == 0) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
	return 0;
}
