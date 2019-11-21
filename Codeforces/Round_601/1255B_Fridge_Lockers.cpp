// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define debug(x) cout << #x << " = " << x << endl
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 1e6;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

void solve() {
	int n, m;
	cin >> n >> m;
	int a[n];
	For(i,0,n) cin >> a[i];
	if (n == 2 or m < n) {
		cout << "-1" << endl;
		return;
	}
	vii ans;
	ll cost = 0LL;
	For(i,0,n) {
		int u = i + 1;
		int v = i + 2;
		if (v > n) v = 1;
		ans.pb(mp(u, v));
		cost += (a[u - 1] + a[v - 1]);
	}
	m -= n;
	vii b;
	For(i,0,n) b.pb(mp(a[i], i));
	sort(all(b));
	int u = b[0].ss;
	int v = b[1].ss;
	For(i,0,m) {
		ans.pb(mp(u + 1, v + 1));
		cost += a[u] + a[v];
	}
	cout << cost << endl;
	m = ans.size();
	For(i,0,m) cout << ans[i].ff << " " << ans[i].ss << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
