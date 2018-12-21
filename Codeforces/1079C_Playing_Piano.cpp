#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX_N = 2e+5;
int a[MAX_N + 1], answer[MAX_N + 1], n;
bool dp[MAX_N + 1][6], used[MAX_N + 1][6];

bool possible(int pos, int finger) {
	if (pos == n) return true;
	if (used[pos][finger]) return dp[pos][finger];
	used[pos][finger] = true;
	for (int i = 1; i <= 5; i++) {
		if (pos == 0 or
			a[pos] < a[pos + 1] and finger < i or
			a[pos] > a[pos + 1] and finger > i or
			a[pos] == a[pos + 1] and finger != i) {
			// si nunca llega al final, siempre retorna false
			dp[pos][finger] = dp[pos][finger] or possible(pos + 1, i);
			if (dp[pos][finger]) {
				answer[pos + 1] = i;
				return true;
			}
		}
	}
	return false;
}

int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (possible(0, 0)) {
		cout << answer[1];
		for (int i = 2; i <= n; i++)
			cout << " " << answer[i];
	} else {
		cout << "-1";
	}
	cout << endl;
	return 0;
}