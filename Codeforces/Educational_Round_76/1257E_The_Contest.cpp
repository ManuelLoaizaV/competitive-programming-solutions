// Your day breaks, your mind aches
// You find that all the words of kindness linger on
// When she no longer needs you
//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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

const int N = 3e5;
const int LG = 20;
const int INF = 1e9;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

struct FenwickTree {
	int tree[N + 1];
	FenwickTree() { memset(tree, 0, sizeof(tree)); }
	void update(int i, int delta) {
		while (i <= N) {
			tree[i] += delta;
			i += (i & -i);
		}
	}
	int query(int i) {
		if (i == 0) return 0;
		int ans = 0;
		while (i > 0) {
			ans += tree[i];
			i -= (i & -i);
		}
		return ans;
	}
} ft[3];

int main() {
	fastio;
	int k[3];
	vi a[3];
	For(i,0,3) cin >> k[i];
	For(i,0,3) {
		For(j,0,k[i]) {
			int aux;
			cin >> aux;
			a[i].pb(aux);
			ft[i].update(aux, 1);
		}
	}
	int ans = INF;
	int n = 0;
	For(i,0,3) n += k[i];
	int dp[N];
	For(i,0,N) dp[i] = INF;
	roF(suffix,n+1,1) {
		int cost = ft[2].query(suffix - 1) + ft[1].query(n) - ft[1].query(suffix - 1);
		if (suffix == n + 1) dp[suffix] = cost;
		else dp[suffix] = min(cost, dp[suffix + 1]);
	}
	// Para cada prefijo, al costo de ese prefijo le sumo el menor de los sufijos encima de el
	For(prefix,0,n+1) {
		int temp = ft[0].query(n) - ft[0].query(prefix) + ft[1].query(prefix);
		temp += dp[prefix + 1];
		ans = min(ans, temp);
	}
	cout << ans << endl;
	return 0;
}
