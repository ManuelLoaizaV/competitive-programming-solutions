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

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Pair search(Long a[], Long pref[], Long l, Long r) {
	Long big_l = l;
	Long big_r = r;
	while (r - l > 2) {
		Long m1 = l + (r - l) / 3;
		Long m2 = r - (r - l) / 3;
		Long f1 = abs(pref[big_r] - pref[m1] - (pref[m1] - pref[big_l - 1]));
		Long f2 = abs(pref[big_r] - pref[m2] - (pref[m2] - pref[big_l - 1]));
		if (f1 > f2) l = m1;
		else r = m2;
	}
	Pair ans = {l, r};
	return ans;
}

void solve() {
	Long n;
	cin >> n;
	Long a[n + 1];
	a[0] = 0LL;
	For(i, 1, n + 1) cin >> a[i];
	Long pref[n + 1];
	pref[0] = 0LL;
	For(i, 1, n + 1) pref[i] = pref[i - 1] + a[i];
	Long ans = INF;
	// a[mid] = ultimo elemento del segundo grupo
	For(mid, 2, n - 1) {
		// a[1 ... mid] y a[mid + 1 ... n]
		Pair left_range = search(a, pref, 1, mid);
		Pair right_range = search(a, pref, mid + 1, n);
		For(i, left_range.first, left_range.second + 1) {
			if (i >= mid) continue;
			For(j, right_range.first, right_range.second + 1) {
				if (j >= n) continue;
				Long P = pref[i];
				Long Q = pref[mid] - pref[i];
				Long R = pref[j] - pref[mid];
				Long S = pref[n] - pref[j];
				Long maxi = max(P, max(Q, max(R, S)));
				Long mini = min(P, min(Q, min(R, S)));
				Long temp = maxi - mini;
				ans = min(ans, temp);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}