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
	string in, out;
	cin >> in >> out;
	char ans[n][n];
	For(i, 0, n) ans[i][i] = 'Y';
	For(i, 0, n) {
		bool ok = true;
		if (out[i] == 'N') ok = false;
		For(j ,i + 1, n) {
			if (ok) {
				if (in[j] == 'Y') ans[i][j] = 'Y';
				else {
					ans[i][j] = 'N';
					ok = false;
				}
			} else {
				ans[i][j] = 'N';
			}
			if (out[j] == 'N') ok = false;
		}
	}
	roF(i, n - 1, 0) {
		bool ok = true;
		if (out[i] == 'N') ok = false;
		roF(j, i - 1, 0) {
			if (ok) {
				if (in[j] == 'Y') ans[i][j] = 'Y';
				else {
					ans[i][j] = 'N';
					ok = false;
				}
			} else {
				ans[i][j] = 'N';
			}
			if (out[j] == 'N') ok = false;
		}
	}
	For(i, 0, n) {
		For(j, 0, n) {
			cout << ans[i][j];
		}
		cout << endl;
	}
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	For(i, 1, t + 1) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}