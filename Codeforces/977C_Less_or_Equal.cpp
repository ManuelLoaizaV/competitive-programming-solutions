//
// Created by ManuelLoaiza on 05/06/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2e+5;
int a[MAX_N];

int main() {
	int n, k, answer;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if (k == 0) {
		if (a[0] == 1) answer = -1;
		else {
			if (n > 1 and a[1] == 1) answer = -1;
			else answer = 1;
		}
	} else {
		answer = a[k - 1];
		if (n > k and a[k] <= answer) answer = -1;
	}
	cout << answer;
	return 0;
}

