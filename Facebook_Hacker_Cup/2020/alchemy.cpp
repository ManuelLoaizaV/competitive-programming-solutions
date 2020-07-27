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

void solve() {
	Long n;
	cin >> n;
	string s;
	cin >> s;
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	For(i, 0, n) cnt[s[i] - 'A']++;
	if (abs(cnt[0] - cnt[1]) == 1) cout << "Y" << endl;
	else cout << "N" << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	For(i, 1, t + 1) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}