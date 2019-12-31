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

const int N = 1e5 + 10;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int tree[N + 1];

void update(int i, int delta) {
	while (i <= N) {
		tree[i] += delta;
		i += (i & -i);
	}
}

int query(int i) {
	int sum = 0;
	while (i > 0) {
		sum += tree[i];
		i -= (i & -i);
	}
	return sum;
}

void solve() {
	int n;
	cin >> n;
	int in[n], out[n];
	For(i,0,n) cin >> in[i];
	For(i,0,n) cin >> out[i];
	int pos[n + 1];
	For(i,0,n) pos[in[i]] = i + 1;
	For(i,0,n) update(i + 1, 1);
	int ans = 0;
	For(i,0,n) {
		int adelante = query(pos[out[i]]) - 1;
		if (adelante > 0) ans++;
		update(pos[out[i]], -1);
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
