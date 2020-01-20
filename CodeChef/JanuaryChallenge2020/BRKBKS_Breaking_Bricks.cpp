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

const int N = 1e6;
const int INF = 1e9;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int s;

int count(int a[]) {
	int acc = 0;
	int hit = 0;
	For(i,0,3) {
		acc += a[i];
		if (acc <= s) hit++;
		else break;
	}
	if (hit == 2) return 2;
	if (a[1] + a[2] <= s) return 2;
	return 3;
}

void solve() {
	cin >> s;
	int w[3], _w[3];
	For(i,0,3) cin >> w[i];
	int sum = 0;
	For(i,0,3) sum += w[i];
	if (sum <= s) {
		cout << 1 << endl;
		return;
	}
	For(i,0,3) _w[i] = w[2 - i];
	int ans = min(count(w), count(_w));
	cout << ans << endl;
}

int main() {
	fastio;
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}
