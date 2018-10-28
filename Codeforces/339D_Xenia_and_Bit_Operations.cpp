//
// Created by ManuelLoaiza on 10/27/18
//
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAX_N = 1 << 17;
int tree[2 * MAX_N];
int n, h;

struct SegmentTree {
	void build() {
		for (int i = n - 1; i > 0; i--) {
			int lg = log2(i);
			int delta = h - lg;
			if (delta & 1) tree[i] = tree[i << 1] |  tree[i << 1 | 1];
			else tree[i] = tree[i << 1] xor tree[i << 1 | 1];
		}
	}
	void update(int i, int value) {
		for (tree[i += n] = value; i > 1; i >>= 1) {
			int lg = log2(i >> 1);
			int delta = h - lg;
			if (delta & 1) tree[i >> 1] = tree[i] | tree[i xor 1];
			else tree[i >> 1] = tree[i] xor tree[i xor 1];		
		}
	}
} st;

int main() {
	fastIO;
	int q;
	cin >> n >> q;
	n = 1 << n;
	h = log2(n);
	for (int i = 0; i < n; i++) cin >> tree[i + n];
	st.build();
	while (q--) {
		int i, value;
		cin >> i >> value;
		st.update(i - 1, value);
		cout << tree[1] << endl;
	}
	return 0;
}