//
// Created by ManuelLoaiza on 10/27/18
//
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAX_N = 1e+5;
int n, tree[2 * MAX_N];

struct SegmentTree {
	void build() {for (int i = n - 1; i > 0; i--) tree[i] = tree[i << 1] + tree[i << 1 | 1];}
	void update(int i, int delta) {
		for (tree[i += n] += delta; i > 0; i >>= 1) tree[i >> 1] = tree[i] + tree[i xor 1];
	}
	int query(int l, int r) {
		int answer = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) answer += tree[l++];
			if (r & 1) answer += tree[--r];
		}
		return answer;
	}
} st;

void solve() {
	int q, type, i, v, j;
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) scanf("%d", &tree[i + n]);
	st.build();
	while (q--) {
		scanf("%d", &type);
		switch (type) {
			case 1:
				scanf("%d", &i);
				printf("%d\n", tree[i + n]);
				st.update(i, -tree[i + n]);
				break;
			case 2:
				scanf("%d %d", &i, &v);
				st.update(i, v);
				break;
			case 3:
				scanf("%d %d", &i, &j);
				printf("%d\n", st.query(i, j + 1));
				break;
		}
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