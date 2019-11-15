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

const int N = 2e5;
const int LG = 20;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int monstruos[N];
ii heroes[N];

struct SparseTable {
	int st[N][LG];
	SparseTable() { memset(st, 0, sizeof(st)); }
	void build(int a[], int n) {
		for (int i = 0; i < n; i++) st[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i + (1 << j) <= n; i++)
				st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	}
	int query(int l, int r) {
		int t = r - l + 1;
		int lg = 31 - __builtin_clz(t);
		return max(st[l][lg], st[r - (1 << lg) + 1][lg]);
	}
} Monstruos, Heroes;

bool creciente(ii &a, ii &b) {
	return a.ss < b.ss;
}

int search(int l, int r, int x) {
	// FFFFF
	if (heroes[r].ss < x) return -1;
	// TTTTT
	if (heroes[l].ss >= x) return l;
	// FFFTTT
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (heroes[m].ss >= x) r = m;
		else l = m;
	}
	// FT
	if (heroes[l].ss >= x) return l;
	return r;
}

void solve() {
	int n, m;
	cin >> n;
	For(i,0,n) cin >> monstruos[i];
	cin >> m;
	For(i,0,m) cin >> heroes[i].ff >> heroes[i].ss;
	Monstruos.build(monstruos, n);
	sort(heroes, heroes + m, creciente);
	int poder[m];
	For(i,0,m) poder[i]= heroes[i].ff;
	Heroes.build(poder, m);
	int ans = 0;
	int from = 0;
	while (from < n) {
		int to = from;
		while (to < n) {
			int max_a = Monstruos.query(from, to);
			int pos = search(0, m - 1, to - from + 1);
			if (pos == -1) {
				if (from == to) {
					cout << "-1" << endl;
					return;
				}
				break;
			}
			int max_p = Heroes.query(pos, m - 1);
			if (max_p >= max_a) {
				if (from == to) ans++;
			} else {
				if (from == to) {
					cout << "-1" << endl;
					return;
				}
				break;
			}
			to++;
		}
		from = to;
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
