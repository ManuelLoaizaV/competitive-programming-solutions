//
// Created by ManuelLoaiza on 05/29/18
//
#include <bits/stdc++.h>

using namespace std;

int main() {
	long double x, y;
	cin >> x >> y;
	long double a = y * log(x);
	long double b = x * log(y);
	if (a < b) cout << "<" << endl;
	else {
		if (a == b) cout << "=" << endl;
		else {
			if (a > b) cout << ">" << endl;
		}
	}
	return 0;
}

