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

bool incr(Pair &a, Pair &b) {
	if (a.second > b.second) return true;
	return false;
}

void solve() {
	Long n;
	cin >> n;
	Long a[n];
	For(i, 0, n) cin >> a[i];
	if (n == 2) {
		if (a[0] == a[1]) cout << 1 << endl;
		else cout << 0 << endl;
		return;
	}
	map<Long, Long> odd, even;
	For(i, 0, n) {
		if (i % 2 == 0) even[a[i]]++;
		else odd[a[i]]++;
	}
	Pair left[n], right[n];
	Long pos = 0;
	for (auto it = odd.begin(); it != odd.end(); it++) {
		Pair aux = {it->first, it->second};
		left[pos] = aux;
		pos++;
	}
	pos = 0;
	for (auto it = even.begin(); it != even.end(); it++) {
		Pair aux = {it->first, it->second};
		right[pos] = aux;
		pos++;
	}
	Long ans = INF;
	Long size_left = odd.size();
	Long size_right = even.size();
	sort(left, left + size_left, incr);
	sort(right, right + size_right, incr);
	For(i, 0, size_left) {
		Long temp = n / 2 - left[i].second;
		if (left[i].first == right[0].first) {
			if (size_right > 1) {
				temp += (n / 2) - right[1].second;
			} else {
				temp += (n / 2);
			}
		} else {
			temp += (n / 2 - right[0].second);
		}
		ans = min(ans, temp);
	}
	For(i, 0, size_right) {
		Long temp = n / 2 - right[i].second;
		if (left[0].first == right[i].first) {
			if (size_left > 1) {
				temp += (n / 2) - left[1].second;
			} else {
				temp += (n / 2);
			}
		} else {
			temp += (n / 2 - left[0].second);
		}
		ans = min(ans, temp);
	}
	ans = min(ans, n - left[0].second);
	ans = min(ans, n - right[0].second);
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}