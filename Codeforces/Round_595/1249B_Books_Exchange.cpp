//#pragma GCC optimize ("Ofast,unroll-loops")
//#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define For(i,a,b) for (int i = a; i < b; i++)
#define roF(i,a,b) for (int i = a; i >= b; i--)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int N = 2e5;
const ll INF = 1e18;
const ld EPS = 10e-9;
vi adj[N + 1];
int comp[N + 1];
int freq[N + 1];
int num_comp;
bool used[N + 1];

int dfs(int u) {
	used[u] = true;
	comp[u] = num_comp;
	freq[num_comp]++;
	int l = adj[u].size();
	For(i,0,l) {
		int v = adj[u][i];
		if (not used[v]) dfs(v);
	}
}

void solve() {
	int n;
	cin >> n;
	int p[n];
	For(i,0,n) cin >> p[i];
	For(i,0,n) adj[i + 1].pb(p[i]);
	For(i,0,n) {
		if (not used[i + 1]) {
			num_comp++;
			dfs(i + 1);
		}
	}
	For(i,0,n) cout << freq[comp[i + 1]] << " ";
	cout << endl;
	num_comp = 0;
	For(i,0,n+1) {
		adj[i].clear();
		comp[i] = 0;
		used[i] = false;
		freq[i] = 0;
	}
}

int main() {
	fastio;
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}
