//
// Created by ManuelLoaiza on 02/05/18.
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e+5;

struct FenwickTree {
	long long tree[MAX + 1];
		
	FenwickTree(int n) {
		for (int i = 0; i <= n; i++) tree[i] = 0;
	}
	
	void update(int i, long long delta) {
		while (i <= MAX) {
			tree[i] += delta;
			i += (i & -i);
		}	
	}
	long long query(int i) {
		long long sum = 0;
		while (i > 0) {
			sum += tree[i];
			i -= (i & -i);
		}	
		return sum;
	}
};

void solve() {
	long long n, c;
	scanf("%lld %lld", &n, &c);
	long long type, l, r, v;
	FenwickTree ft1(n), ft2(n);
	
	while (c--) {
		scanf("%lld %lld %lld", &type, &l, &r);
		if (type == 0) {
			scanf("%lld", &v);
			ft1.update(l, v);
			ft1.update(r + 1, -v);
			ft2.update(l, v * (l - 1));
			ft2.update(r + 1, - v * r);
		} else {
			long long result = (ft1.query(r) * r - ft2.query(r)) - (ft1.query(l - 1) * (l - 1) - ft2.query(l - 1));
			printf("%lld\n", result);
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
