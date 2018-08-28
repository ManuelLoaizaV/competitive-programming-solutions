//
// Created by ManuelLoaiza on 08/27/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N = 132674;

struct Segment {
	int l;
	int r;
};

Segment rw[MAX_N], rh[MAX_N], w1[MAX_N], w2[MAX_N], h1[MAX_N], h2[MAX_N];

bool exist(int x1, int y1, int x2, int y2) {
	if (x1 <= x2 and y1 <= y2) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n ; i++) {
		cin >> rw[i].l >> rh[i].l;
		cin >> rw[i].r >> rh[i].r;
	}
	
	// width
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			w1[i].l = rw[i].l;
			w1[i].r = rw[i].r;	
		}
		else {
			w1[i].l = max(w1[i - 1].l, rw[i].l);	
			w1[i].r = min(w1[i - 1].r, rw[i].r);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			w2[i].l = rw[i].l;
			w2[i].r = rw[i].r;	
		}
		else {
			w2[i].l = max(w2[i + 1].l, rw[i].l);	
			w2[i].r = min(w2[i + 1].r, rw[i].r);
		}
	}
	
	// height
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			h1[i].l = rh[i].l;
			h1[i].r = rh[i].r;	
		}
		else {
			h1[i].l = max(h1[i - 1].l, rh[i].l);	
			h1[i].r = min(h1[i - 1].r, rh[i].r);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1) {
			h2[i].l = rh[i].l;
			h2[i].r = rh[i].r;	
		}
		else {
			h2[i].l = max(h2[i + 1].l, rh[i].l);	
			h2[i].r = min(h2[i + 1].r, rh[i].r);
		}
	}
	
	int x1, y1, x2, y2;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			x1 = w2[i + 1].l;
			x2 = w2[i + 1].r;
			y1 = h2[i + 1].l;
			y2 = h2[i + 1].r;
		} else {
			if (i == n - 1) {
				x1 = w1[i - 1].l;
				x2 = w1[i - 1].r;
				y1 = h1[i - 1].l;
				y2 = h1[i - 1].r;	
			} else {
				x1 = max(w1[i - 1].l, w2[i + 1].l);
				x2 = min(w1[i - 1].r, w2[i + 1].r);
				y1 = max(h1[i - 1].l, h2[i + 1].l);
				y2 = min(h1[i - 1].r, h2[i + 1].r);
			}
		}
		if (exist(x1, y1, x2, y2)) break;
	}
	cout << x1 << " " << y1 << endl;
	return 0;
}
