#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;

const int MAX_N = 100002;
char number[MAX_N + 1];
int tree[MAX_N + 1];

struct FenwickTree {
	void initialize() {
		for (int i = 0; i <= MAX_N; i++) tree[i] = 0;
	}
	void update(int i, int delta) {
		while (i <= MAX_N) {
			tree[i] += delta;
			i += (i & -i);
		}
	}
	int query(int i) {
		int answer = 0;
		while (i > 0) {
			answer += tree[i];
			i -= (i & -i);
		}
		return answer;
	}
} ft;

void solve() {
	scanf("%s", number);
	getchar();
	ft.initialize();
	int q;
	scanf("%d", &q);
	getchar();
	while (q--) {
		char c;
		scanf("%c", &c);	
		if (c == 'I') {
			int l, r;
			scanf("%d %d", &l, &r);
			ft.update(l, 1);
			ft.update(r + 1, -1);
		} else {
			int i;
			scanf("%d", &i);
			int mod = ft.query(i);
			if (mod % 2 == 0) printf("%c\n", number[i - 1]);
			else {
				if (number[i - 1] == '0') printf("1\n");
				else printf("0\n");
			}
		}
		getchar();
	}
}

int main() {
	fastIO;
	int t;
	scanf("%d", &t);
	getchar();
	for (int i = 1; i <= t; i++) {
		printf("Case %d:\n", i);
		solve();
	}
	return 0;
}