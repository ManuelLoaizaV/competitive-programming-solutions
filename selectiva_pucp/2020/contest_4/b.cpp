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

Long search(vector<Long> &div, Long target) {
	Long l = 0;
	Long r = div.size() - 1;
	if (div[l] > target) return -1;
	if (div[r] <= target) return r;
	while (r - l > 1) {
		Long mid = (l + r) / 2;
		if (div[mid] <= target) l = mid;
		else r = mid;
	}
	if (div[r] <= target) return r;
	return l;
}

void solve() {
	Long a, b;
	cin >> a >> b;
	vector<Long> div_a;
	for (Long i = 1; i * i <= a; i++) {
		if (a % i == 0) {
			Long j = a / i;
			div_a.push_back(i);
			if (i != j) div_a.push_back(j);
		}
	}
	vector<Long> div;
	Long size_a = div_a.size();
	For(i, 0, size_a) if (b % div_a[i] == 0) div.push_back(div_a[i]);
	sort(all(div));
	// Queries
	Long q;
	cin >> q;
	while (q--) {
		Long l, r;
		cin >> l >> r;
		Long pos = search(div, r);
		if (pos == -1) {
			cout << -1 << endl;
		} else {
			if (div[pos] >= l) cout << div[pos] << endl;
			else cout << -1 << endl;
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