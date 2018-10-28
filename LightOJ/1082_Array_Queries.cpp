//
// Created by ManuelLoaiza on 10/26/18
//
#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

const int MAX_N = 1e+5;
const int INF = MAX_N + 1;

int tree[2 * MAX_N];

struct SegmentTree {
	int n;
	int f(int a, int b) {return min(a, b);}
	void build() {for (int i = n - 1; i > 0; i--) tree[i] = f(tree[i << 1], tree[i << 1 | 1]);}
	int query(int l, int r) {
		int answer = INF;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) answer = f(answer, tree[l++]);
			if (r & 1) answer = f(answer, tree[--r]);
		}
		return answer;
	}
} st;

void solve() {
	int q;
	scanf("%d %d", &st.n, &q);
	for (int i = 0; i < st.n; i++) scanf("%d", &tree[i + st.n]);
	st.build();
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", st.query(l - 1, r));
	}
}

int main() {
	fastIO;
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case %d:\n", i);
		solve();
	}
	return 0;
}