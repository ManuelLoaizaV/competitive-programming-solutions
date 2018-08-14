//
// Created by ManuelLoaiza on 05/29/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 3e+3;

struct A {
	int index;
	long long s;
	long long c;
	bool operator < (A b) const {
		if (s == b.s) return index < b.index;
		return s < b.s;
	}	
} a[MAX_N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i].index = i;
		cin >> a[i].s;
	}
	for (int i = 0; i < n; i++) cin >> a[i].c;
	
	sort(a, a + n);
	long long answer = -1;
	for (int i = 1; i < n - 1; i++) {
		
		bool left = false;
		long long leftCost;
		for (int j = 0; j < i; j++) {
			if (a[j].s < a[i].s and a[j].index < a[i].index) {
				if (not left) leftCost = a[j].c;
				else leftCost = min(leftCost, a[j].c);
				left = true;
			}
		}
		
		bool right = false;
		long long rightCost;
		for (int j = i + 1; j < n; j++) {
			if (a[j].s > a[i].s and a[j].index > a[i].index) {
				if (not right) rightCost = a[j].c;
				else rightCost = min(rightCost, a[j].c);
				right = true;
			}
		}
		
		if (left and right) {
			long long sum = a[i].c + leftCost + rightCost;
			if (answer == -1) answer = sum;
			else answer = min(answer, sum);
		}
	}
	cout << answer << endl;
	return 0;
}

