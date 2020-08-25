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

typedef long double Double;
typedef long long Long;
typedef pair<Long, Long> Pair;
typedef vector<Long> Vector;
typedef vector<Pair> PairVector;

const int N = 1e6;
const Long INF = 1e16;
const Double EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

Long count(Long n, Long x) {
	Long cnt = 0;
	Long y = x;
	while (y <= n) {
		cnt += (n / y);
		y *= x;
	}
	return cnt;
}

vector<Pair> primes;
Long zeros(Long number, Long base) {
	Long ans;
	Long size_primes = primes.size();
	for (Long pos = 0; pos < size_primes; pos++) {
		if (pos == 0) ans = count(number, primes[0].first) / primes[0].second;
		else ans = min(ans, count(number, primes[pos].first) / primes[pos].second);
	}
	return ans;
}

Long solve() {
	Long b, n;
	cin >> b >> n;
	Long left = 1LL;
	Long right = INF;
	// precalculo
	primes.clear();
	Long copy = b;
	for (Long p = 2; p <= b; p++) {
		if (copy % p == 0) {
			Long cnt = 0;
			while (copy % p == 0) {
				copy /= p;
				cnt++;
			}
			primes.push_back({p, cnt});
		}
	}
	if (copy > 1) primes.push_back({copy, 1LL});
	// binary search
	while (right - left > 1) {
		Long mid = (left + right) / 2;
		Long cnt = zeros(mid, b);
		if (cnt >= n) right = mid;
		else left = mid;
	}
	// respondo
	Long cnt = zeros(left, b);
	if (cnt >= n) {
		if (cnt == n) return left;
		return -1;
	}
	cnt = zeros(right, b);
	if (cnt == n) return right;
	return -1;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) cout << solve() << endl;
	return 0;
}