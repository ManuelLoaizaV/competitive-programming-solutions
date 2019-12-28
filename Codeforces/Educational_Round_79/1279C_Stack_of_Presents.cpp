// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
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

int n, m;
ll tree[N];

void init() {
	For(i,0,n+10) tree[i] = 0;
}

void update(int i, ll delta) {
	while (i <= n) {
		tree[i] += delta;
		i += (i & -i);
	}
}

ll query(int i) {
	ll sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

void solve() {
	cin >> n >> m;
	init();
	ll a[n], b[m];
	ll max_pos = -1;
	For(i,0,n) cin >> a[i];
	For(i,0,m) cin >> b[i];
	ll ans = 0;
	ll pos[n + 1];
	For(i,0,n) pos[a[i]] = i + 1;
	For(i,1,n+1) update(i, 1LL);
	For(i,0,m) {
		if (max_pos > pos[b[i]]) ans++;
		else {
			ll k = query(pos[b[i]]) - 1LL;
			ans += (2LL * k + 1LL);
			max_pos = max(max_pos, pos[b[i]]);
		}
		update(pos[b[i]], -1LL);
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
