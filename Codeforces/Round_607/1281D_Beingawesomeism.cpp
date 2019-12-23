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

const int N = 60;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

string g[N];

void solve() {
	int r, c;
	cin >> r >> c;
	For(i,0,r) cin >> g[i];
	int freq[2];
	memset(freq, 0, sizeof(freq));
	For(i,0,r)
		For(j,0,c)
			if (g[i][j] == 'A') freq[0]++;
			else freq[1]++;
	// Quiero todo A
	if (freq[0] == 0) {
		cout << "MORTAL" << endl;
		return;
	}
	if (freq[1] == 0) {
		cout << "0" << endl;
		return;
	}
	// Si existe algun borde 1
	int count = 0;
	For(i,0,c) if (g[0][i] == 'A') count++;
	if (count == c) {
		cout << 1 << endl;
		return;
	}
	count = 0;
	For(i,0,c) if (g[r - 1][i] == 'A') count++;
	if (count == c) {
		cout << 1 << endl;
		return;
	}
	count = 0;
	For(i,0,r) if (g[i][0] == 'A') count++;
	if (count == r) {
		cout << 1 << endl;
		return;
	}
	count = 0;
	For(i,0,r) if (g[i][c - 1] == 'A') count++;
	if (count == r) {
		cout << 1 << endl;
		return;
	}
	// Si existe alguna linea 2
	For(i,0,r) {
		count = 0;
		For(j,0,c) if (g[i][j] == 'A') count++;
		if (count == c) {
			cout << 2 << endl;
			return;
		}
	}
	For(i,0,c) {
		count = 0;
		For(j,0,r) if (g[j][i] == 'A') count++;
		if (count == r) {
			cout << 2 << endl;
			return;
		}
	}
	if (g[0][0] == 'A' or g[r-1][0] == 'A' or g[0][c - 1] == 'A' or g[r - 1][c - 1] == 'A') {
		cout << 2 << endl;
		return;
	}
	// Si existe alguna linea incompleta desde borde 3
	For(i,0,r) {
		if (g[i][0] == 'A' or g[i][c - 1] == 'A') {
			cout << 3 << endl;
			return;
		}
	}
	For(i,0,c) {
		if (g[0][i] == 'A' or g[r - 1][i] == 'A') {
			cout << 3 << endl;
			return;
		}
	}
	// sino 4
	cout << "4" << endl;
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}
