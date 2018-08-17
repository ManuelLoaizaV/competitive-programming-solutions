//
// Created by ManuelLoaiza on 06/09/18
//
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const ld INF = 1e+9;
const int MAX_N = 20;

struct Contestant {
	ld r;
	ld k;
} c[MAX_N];

ld f(ld r, ld k, int n) {
	ld margin = INF; 
	ld cheaterTime = r / c[n - 1].r + k / c[n - 1].k;
	for (int i = 0; i < n - 1; i++) {	
		ld competitorTime = r / c[i].r + k / c[i].k;
		ld actualMargin = competitorTime - cheaterTime;
		margin = min(margin, actualMargin);
	}
	return margin;
}

void ternarySearch(ld l, ld r, int n, ld T) {
	ld margin = INF;
	while (r - l > EPS) {
		ld m1 = l + (r - l) / 3;
		ld m2 = l + (r - l) * 2 / 3;
		ld f1 = f(m1, T - m1, n);
		ld f2 = f(m2, T - m2, n);
		if (f1 <= f2) l = m1;
		else r = m2;
		margin = max(f1, f2);
	}
	margin = margin * 3600;
	ld R = (l + r) / 2;
	ld K = T - R;
	if (margin < 0) {
		cout << "The cheater cannot win." << endl;	
	} else {
		cout << "The cheater can win by " << setprecision(0) << fixed << margin; 
		cout << setprecision(2) << fixed << " seconds with r = " << R << "km and k = " << K << "km." << endl;	
	}
}

void solve(ld t) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> c[i].r >> c[i].k;
	ternarySearch(0, t, n, t);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ld t;
	while (cin >> t) solve(t);
	return 0;
}

