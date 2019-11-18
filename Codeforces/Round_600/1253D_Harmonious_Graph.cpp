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

const int N = 200005;
const ll INF = 1e18;
const ld EPS = 10e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll a, ll b) { return uniform_int_distribution<ll> (a, b) (rng); }

int parent[N];
int maxi[N];

void make_set() {
	For(i,0,N) parent[i] = maxi[i] = i;
}

int find_set(int u) {
	if (parent[u] == u) return u;
	parent[u] = find_set(parent[u]);
	return parent[u];
}

bool same_set(int u, int v) {
	return find_set(u) == find_set(v);
}

void union_sets(int u, int v) {
	int p_u = find_set(u);
	int p_v = find_set(v);
	if (p_u != p_v) {
		maxi[p_u] = max(maxi[p_u], maxi[p_v]);
		parent[p_v] = p_u;
	}
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	make_set();
	For(i,0,m) {
		int u, v;
		cin >> u >> v;
		union_sets(u, v);
	}
	int ans = 0;
	For(l,1,n+1) {
		int p_l = find_set(l);
		int r = maxi[p_l];
		For(m,l,r+1) {
			if (same_set(l, m)) continue;
			union_sets(l, m);
			ans++;
			r = maxi[find_set(l)];
		}
		l = r;
	}
	cout << ans << endl;
	return 0;
}
