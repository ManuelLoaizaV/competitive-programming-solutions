// Gracias, Rodolfo
// Gracias, Roman
// Gracias, Maxi
// Gracias, MarcosK
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()
#define SZ(v) ((int)v.size())

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

/*
const int N = 1e5, LG = 17;
int st[N][LG + 1];

void build(int a[], int n) {
	for (int i = 0; i < n; i++) st[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int t = r - l + 1;
	int lg = 32 - (__builtin_clz(t) + 1);
	return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
}
*/
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	//build(a, n);
	int control = min(k, m - 1);
	int falta = m - control - 1;
	int x = -1;
	for (int i = 0; i <= control; i++) {
		int ini = i;
		int fin = control - i;
		int l = ini;
		int r = n - 1 - fin;
		/*
		int l1 = l;
		int r1 = min(r, l + falta - 1);
		int l2 = max(l, r - falta + 1);
		int r2 = r;
		int y1 = query(l1, r1);
		int y2 = query(l2, r2);
		debug(l, r);
		debug(l1, r1, y1);
		debug(l2, r2, y2);
		int y = min(y1, y2);
		x = max(x, y);
		*/
		int temp = 1e9+10;
		for (int j = 0; j <= falta; j++) {
			int _l = l + j;
			int rem = falta - j;
			int _r = r - rem;
			int y = max(a[_l], a[_r]);
			//debug(l, r, _l, _r, y);
			temp = min(temp, y);
		}
		x = max(x, temp);
	}
	cout << x << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}