//
// Created by ManuelLoaiza on 26/08/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 3e+5;

struct Segment {
	int l;
	int r;
};

Segment a[MAX_N], max_min_1[MAX_N], max_min_2[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
	
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			max_min_1[i].l = a[i].l;
			max_min_1[i].r = a[i].r;
		}
		else {
			max_min_1[i].l = max(max_min_1[i - 1].l, a[i].l);
			max_min_1[i].r = min(max_min_1[i - 1].r, a[i].r);
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			max_min_2[i].l = a[i].l;
			max_min_2[i].r = a[i].r;
		}
		else {
			max_min_2[i].l = max(max_min_2[i + 1].l, a[i].l);
			max_min_2[i].r = min(max_min_2[i + 1].r, a[i].r);
		}
	}
	
	int l, r, length, answer = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			l = max_min_2[i + 1].l;
			r = max_min_2[i + 1].r;
		} else {
			if (i == n - 1) {
				l = max_min_1[i - 1].l;
				r = max_min_1[i - 1].r;
			} else {
				l = max(max_min_1[i - 1].l, max_min_2[i + 1].l);
				r = min(max_min_1[i - 1].r, max_min_2[i + 1].r);
			}
		}
		length = max(r - l, 0);
		answer = max(answer, length);
	}
	cout << answer << endl;
	return 0;
}
