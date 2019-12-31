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

const int N = 3e5;
const ll INF = 1e18;
const ld EPS = 10e-9;
const int LG = 18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

// mini, maxi
ii st[N][LG + 1];

void build(int a[], int n) {
	for (int i = 0; i < n; i++) st[i][0] = {a[i], a[i]};
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = {min(st[i][j - 1].ff, st[i + (1 << (j - 1))][j - 1].ff), max(st[i][j - 1].ss, st[i + (1 << (j - 1))][j - 1].ss)};
}

ii query(int l, int r) {
	int t = r - l + 1;
	int lg = 32 - (__builtin_clz(t) + 1);
	return {min(st[l][lg].ff, st[r - (1 << lg) + 1][lg].ff), max(st[l][lg].ss, st[r - (1 << lg) + 1][lg].ss)};
}

int coolness(int x) { return x / 2 - (x % 2 == 0); }

// Busco el indice del primero > x
int sup(int l, int r, int x) {
	// TTTT
	if (query(l, l).ss > x) return  l;
	// FFFF
	if (query(l, r).ss <= x) return -1;
	int ini = l;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (query(ini, m).ss > x) r = m;
		else l = m;
	}
	if (query(ini, l).ss > x) return l;
	return r;
}

// Busco el indice del primero <= x
int inf(int l, int r, int x) {
	//debug(x);
	//debug(l);
	// TTTT
	if (query(l, l).ff <= x) return l;
	// FFFF
	//debug(r);
	if (query(l, r).ff > x) return -1;
	int ini = l;
	while (r - l > 1) {
		int m = (l + r) / 2;
		//debug(l);
		//debug(r);
		//debug(m);
		//debug(query(ini, m).ff);
		if (query(ini, m).ff <= x) r = m;
		else l = m;
	}
	//debug(l);
	if (query(ini, l).ff <= x) return l;
	//debug(r);
	return r;
}

void solve() {
	int n;
	cin >> n;
	int a[n];
	For(i,0,n) cin >> a[i];
	int b[3 * n];
	For(i,0,n) b[i] = b[i + n] = b[i + 2 * n] = a[i]; 
	build(b, 3 * n);
	int c[3 * n];
	For(i,0,3*n) c[i] = -1;
	roF(i,3*n-1,0) {
		//debug(i);
		// Busco el primero que supera ai
		int j = sup(i, 3 * n - 1, b[i]);
		// Busco el primero que es inferior ai / 2
		int k = inf(i, 3 * n - 1, coolness(b[i]));
		//debug(j);
		//debug(k);
		if (j == -1) {
			if (k == -1) {
				c[i] = -1;
			} else {
				c[i] = k - i;
			}
		} else {
			if (k == -1) {
				if (c[j] == -1) c[i] = -1;
				else c[i] = c[j] + j - i;
			} else {
				if (j > k) c[i] = k - i;
				else {
					if (c[j] == -1) c[i] = -1;
					else c[i] = c[j] + j - i;
				}
			}
		}
	}
	For(i,0,n) {
		if (i > 0) cout << " ";
		cout << c[i];
	}
	cout << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
