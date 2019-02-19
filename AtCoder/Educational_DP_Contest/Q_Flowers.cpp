#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long Long;

const int MAX_N = 2e5;
Long tree[2 * MAX_N + 5];
Long dp[MAX_N + 5];
int n;

void update(int i, Long value) {
	for (tree[i += (n + 1)] = value; i > 1; i >>= 1) {
		tree[i >> 1] = max(tree[i], tree[i xor 1]);
	}
}

Long query(int l, int r) {
	Long ret = 0LL;
	for (l += (n + 1), r += (n + 1); l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret = max(ret, tree[l++]);
		if (r & 1) ret = max(ret, tree[--r]);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int h[n];
	Long b[n];
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		dp[h[i]] = b[i] + query(0, h[i]);
		update(h[i], dp[h[i]]);
	}
	Long answer = query(0, n + 1);
	cout << answer << endl;
	return 0;
}