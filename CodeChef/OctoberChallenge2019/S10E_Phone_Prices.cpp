#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = 1e9;

void solve() {
	int n;
	cin >> n;
	int p[n];
	For(i,0,n) cin >> p[i];
	int count = 0;
	For(i,0,n) {
		int mini = INF;
		roF(j,i-1,max(0,i-5)) mini = min(mini, p[j]);
		if (p[i] < mini) count++;
	}
	cout << count << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
