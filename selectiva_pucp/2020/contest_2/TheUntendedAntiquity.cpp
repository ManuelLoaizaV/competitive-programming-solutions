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

const Long N = 2505;
const Long INF = 1e18;
const Long MIERDA = 1e10;
const Double EPS = 10e-9;
const Pair MOD = {998244353LL, 1e9 + 7};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Pair tree[N + 1][N + 1];

void update(Long i, Long j, Pair delta) {
	while (i <= N) {
		Long y = j;
		while (y <= N) {
			tree[i][y].first += delta.first;
			tree[i][y].second += delta.second;
			y +=  (y & -y);
		}
		i += (i & -i);
	}
}

Pair query(Long i, Long j) {
	Pair ans = {0, 0};
	while (i > 0) {
		Long y = j;
		while (y > 0) {
			ans.first += tree[i][y].first;
			ans.second += tree[i][y].second;
			y -= (y & -y);
		}
		i -= (i & -i);
	}
	return ans;
}

void update(Pair ld, Pair ru, Pair delta) {
	update(ld.first, ld.second, delta);
	update(ru.first + 1, ld.second, {-delta.first, -delta.second});
	update(ld.first, ru.second + 1, {-delta.first, -delta.second});
	update(ru.first + 1, ru.second + 1, delta);
}

Pair Hash(Pair p1, Pair p2, Long q) {
	Pair ans;
	ans.first = MIERDA + MOD.first + q;
	ans.second = MIERDA + MOD.second - q;
	return ans;
}

void solve() {
	Long n, m, q;
	cin >> n >> m >> q;
	map<pair<Pair, Pair>, Pair> barrier;
	while (q--) {
		Long t;
		Pair p1, p2;
		cin >> t >> p1.first >> p1.second >> p2.first >> p2.second;
		Pair ld = {min(p1.first, p2.first), min(p1.second, p2.second)};
		Pair ru = {max(p1.first, p2.first), max(p1.second, p2.second)};
		pair<Pair, Pair> rec = {ld, ru};
		if (t == 1) {
			Pair val = Hash(ld, ru, q);
			update(ld, ru, val);
			barrier[rec] = val;
		}
		if (t == 2) {
			Pair val = barrier[rec];
			update(ld, ru, {-val.first, -val.second});
			barrier.erase(rec);
		}
		if (t == 3) {
			ld = p1;
			ru = p2;
			Pair val1 = query(ld.first, ld.second);
			Pair val2 = query(ru.first, ru.second);
			if (val1 == val2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}
