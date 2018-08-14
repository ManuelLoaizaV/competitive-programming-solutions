//
// Created by ManuelLoaiza on 03/25/18
//
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e+6;
long long tree[MAX + 1];
long long numbers[MAX + 1];
long long ac[MAX + 1];

struct FenwickTree {
	void update(int i, long long delta) {
		while (i <= MAX) {
			tree[i] += delta;
			i += (i & -i);
		}	
	}
	
	long long query(long long i) {
		long long sum = 0;
		while (i > 0) {
			sum += tree[i];
			i -= (i & -i);
		}
		return sum;
	}
} ft;

int main() {
	long long n, q;
	scanf("%lld %lld", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &numbers[i]);
		ac[i] = ac[i - 1] + numbers[i];
	}
	char action;
	long long x, y;
	long long answer;
	while (q--) {
		//scanf("%c %lld %lld", &action, &x, &y);
		cin >> action >> x >> y;
		if (action == 'S') {
			answer = ac[y + 1] - ac[x] + ft.query(y + 1) - ft.query(x);
			printf("%lld\n", answer);
		} else {
			if (action == 'G') {
				ft.update(x + 1, y);
			} else {
				ft.update(x + 1, -y);
			}
		}
	}
	return 0;
}
