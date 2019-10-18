#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a ; i >= b; i--)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int  N = 1e6;
const ll INF = 1e18;
const ld EPS = 1e-9;

int freq[N + 1];

void mod(int n, int delta) {
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			int j = n / i;
			freq[i] += delta;
			if (i != j) freq[j] += delta;
		}
	}
}

void solve() {
	memset(freq, 0, sizeof(freq));
	int n;
	cin >> n;
	int a[n];
	For(i,0,n) cin >> a[i];
	int ans = 0;
	For(i,0,n) mod(a[i], 1);
	roF(i,n-1,0) {
		mod(a[i], -1);
		ans = max(ans, freq[a[i]]);
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
