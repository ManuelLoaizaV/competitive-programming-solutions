// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const int N = 1e5;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int n;
ii R[N], ranges[N], ord_ini[N], ord_fin[N];
unordered_set<int> uni;
unordered_map<int, int> h;
vi unicos;
std::unordered_set<int>::iterator it;

bool comp_ini(const ii &a, const ii &b) { 
	if (a.ff == b.ff) a.ss < b.ss;
	return a.ff < b.ff;
}

bool comp_fin(const ii &a, const ii &b) { 
	if (a.ss == b.ss) a.ff < b.ff;
	return a.ss < b.ss;
}

int search_fin(int x, ii a[]) {
	int l = 0;
	int r = n - 1;
	// TTTT
	if (a[r].ss <= x) return r + 1;
	// FFFF
	if (a[l].ss > x) return 0;
	// TTFF
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (a[m].ss <= x) l = m;
		else r = m;
	}
	// TF
	if (a[r].ss <= x) return r + 1;
	return l + 1;
}

int search_ini(int x, ii a[]) {
	int l = 0;
	int r = n - 1;
	// TTTT
	if (a[l].ff >= x) return n;
	// FFFF
	if (a[r].ff < x) return 0;
	// FFTT
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (a[m].ff >= x) r = m;
		else l = m;
	}
	// FT
	if (a[l].ff >= x) return n - l;
	return n - r;
}

void solve() {
	scanf("%d", &n);
	uni.clear();
	h.clear();
	unicos.clear();
	For(i,0,n) {
		scanf("%d %d", &R[i].ff, &R[i].ss);
		uni.insert(R[i].ff);
		uni.insert(R[i].ss);
	}
	vi unicos;
	for (it = uni.begin(); it != uni.end(); it++) unicos.pb(*it);
	sort(all(unicos));
	int sz = unicos.size();
	For(i,0,sz) h[unicos[i]] = i;
	For(i,0,n) {
		ranges[i].ff = h[R[i].ff];
		ranges[i].ss = h[R[i].ss];
		ord_ini[i] = ord_fin[i] = ranges[i];
	}
	sort(ord_ini, ord_ini + n, comp_ini);
	sort(ord_fin, ord_fin + n, comp_fin);
	bool possible = false;
	int ans = N;
	For(i,0,sz) {
		int izq = search_fin(i, ord_fin);
		int der = search_ini(i + 1, ord_ini);
		if (izq == 0 or der == 0) continue;
		int eliminar = n - izq - der;
		possible = true;
		ans = min(ans, eliminar);
	}
	if (possible) printf("%d\n", ans);
	else printf("-1\n");
}

int main() {
	fastio;
	int t;
	scanf("%d", &t);
	while (t--) solve();
	return 0;
}
