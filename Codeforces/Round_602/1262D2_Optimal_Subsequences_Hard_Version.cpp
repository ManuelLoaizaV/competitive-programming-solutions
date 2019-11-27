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
typedef pair<int, pair<int, int>> trio;

const int N = 200005;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

bool comp(ii a, ii b) {
	if (a.ff != b.ff) return a.ff > b.ff;
	return a.ss < b.ss;
}

int tree[N + 5];

void update(int i, int delta) {
	while (i <= N) {
		tree[i] += delta;
		i += (i & -i);
	}
}

int query(int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

int search(int l, int r, int x) {
	// FFFF
	if (query(r) < x) return -1;
	// TTTT
	if (query(l) >= x) return l;
	// FFTT
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (query(m) >= x) r = m;
		else l = m;
	}
	if (query(l) >= x) return l;
	return r;
}

int main() {
	fastio;
	int n;
	cin >> n;
	int a[n];
	For(i,0,n) cin >> a[i];
	vii a_pos;
	For(i,0,n) a_pos.pb(mp(a[i], i + 1));
	sort(all(a_pos), comp);
	int m;
	cin >> m;
	trio q[m];
	int ans[m];
	For(i,0,m) {
		cin >> q[i].ff >> q[i].ss.ff;
		q[i].ss.ss = i;
	}
	sort(q, q + m);
	int actual = 1;
	For(i,0,m) {
		int k = q[i].ff;
		int pos_k = q[i].ss.ff;
		int pos = q[i].ss.ss;
		while (actual <= k) {
			int men = a_pos[actual - 1].ff;
			int pos_men = a_pos[actual - 1].ss;
			update(pos_men, 1);
			actual++;
		}
		ans[pos] = a[search(1, n, pos_k) - 1];
	}
	For(i,0,m) cout << ans[i] << endl;
	return 0;
}
