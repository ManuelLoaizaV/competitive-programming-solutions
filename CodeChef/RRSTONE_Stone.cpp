//
// Created by ManuelLoaiza on 05/21/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e+5;
long long a[MAX_N];

void print(long long n, long long k, long long maxValue, long long minValue) {
	if (k == 0) {
		for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
		}
	}
	else {
		if (k % 2 == 0) {
			for (int i = 0; i < n; i++) {
				cout << a[i] - minValue << " ";
			}
		} else {
			for (int i = 0; i < n; i++) {
				cout << maxValue - a[i] << " ";
			}
		}
	}
}

int main() {
	long long n, k;
	long long maxValue = -2e+9;
	long long minValue = 2e+9;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxValue = max(maxValue, a[i]);
		minValue = min(minValue, a[i]);
	}
	print(n, k, maxValue, minValue);
	return 0;
}
