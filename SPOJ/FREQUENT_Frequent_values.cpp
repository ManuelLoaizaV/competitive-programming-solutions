//
// Created by ManuelLoaiza on 10/27/18
//
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
using namespace std;;
const int MAX_N = 1e+5;
int tree[2 * MAX_N];
int n;

struct SegmentTree{
	void build(vector<int> acc) {
		for (int i = 0; i < n; i++) tree[i + n] = acc[i];
		for (int i = n - 1; i > 0; i--) tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
	}
	// query [l, r>
	int query(int l, int r) {
		int answer = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) answer = max(answer, tree[l++]);
			if (r & 1) answer = max(answer, tree[--r]);
		}
		return answer;
	}
} st;

void solve(int xd) {
	int q, aux, last;
	cin >> q;
	vector<int> freq;
	for (int i = 0; i < xd; i++) {
		cin >> aux;
		int l = freq.size();
		if (l == 0 or aux != last) freq.pb(1);
		else freq[l - 1]++;
		last = aux;
	}
	n = freq.size();
	vector<int> acc;
	for (int i = 0; i < n; i++) {
		if (i == 0) acc.pb(freq[i]);
		else acc.pb(freq[i] + acc[i - 1]);
	}
	st.build(freq);
	while (q--) {
		int l, r;
		cin >> l >> r;
		int leftIndex = lower_bound(acc.begin(), acc.end(), l) - acc.begin();
		int rightIndex = lower_bound(acc.begin(), acc.end(), r) - acc.begin();
		int answer;
		if (leftIndex == rightIndex) {
			answer = r - l + 1;
		} else {
			int leftCount = acc[leftIndex] - l + 1;
			int rightCount = r - acc[rightIndex - 1];
			answer = max(leftCount, rightCount);
			if (leftIndex + 1 < rightIndex) answer = max(answer, st.query(leftIndex + 1, rightIndex));
		}
		cout << answer << endl;
	}
}

int main() {
	fastIO;	
	int xd;
	while (cin >> xd) {
		if (xd == 0) break;
		solve(xd);
	}
	return 0;
}