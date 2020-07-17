// Gracias, Rodolfo
// Gracias, MarcosK
// Gracias, Graphter
// Obrigado, Dilson
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (Long i = a; i < b; i++)
#define roF(i,a,b) for (Long i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) (v).begin(),(v).end()

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

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 3e5;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long search(vector<Long>& a, Long falta) {
	Long l = 0;
	Long r = a.size() - 1;
	if (a[l] >= falta) return l;
	if (a[r] < falta) return r + 1;
	while (r - l > 1) {
		Long m = (l + r) / 2;
		if (a[m] >= falta) r = m;
		else l = m;
	}
	if (a[l] >= falta) return l;
	return r;
}

void solve() {
	Long n, p;
	cin >> n >> p;
	vector<int> apunto[n], apuntado_por[n];
	Long deg[n];
	For(i, 0, n) deg[i] = 0LL;
	For(i, 0, n) {
		Long x, y;
		cin >> x >> y;
		x--;
		y--;
		apunto[i].push_back(x);
		apunto[i].push_back(y);
		apuntado_por[x].push_back(i);
		apuntado_por[y].push_back(i);
		deg[x]++;
		deg[y]++;
	}
	vector<Long> deg_incr;
	For(i, 0, n) deg_incr.push_back(deg[i]);
	sort(all(deg_incr));	
	Long ans = 0;
	// (x, y) son los acusados
	For(i, 0, n) {
		Long falta = max(0LL, p - deg[i]);
		Long cumplen = n - search(deg_incr, falta);
		if (deg[i] >= falta) cumplen--;
		map<Long, Long> acc;
		Long sz = apuntado_por[i].size();
		For(j, 0, sz) {
			Long acusador = apuntado_por[i][j];
			For(k, 0, 2) if (apunto[acusador][k] != i) acc[apunto[acusador][k]]++;
		}
		for (auto it = acc.begin(); it != acc.end(); it++) {
			Long complice = it->first;
			Long veces = it->second;
			if (deg[complice] >= falta and deg[i] + deg[complice] - veces < p) cumplen--;
		}
		//debug(i, deg[i], cumplen, ans);
		ans += cumplen;
	}
	ans /= 2;
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}